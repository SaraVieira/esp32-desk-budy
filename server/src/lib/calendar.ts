import { differenceInDays, format, formatDistanceStrict, getTime, isAfter } from "date-fns"
import { isToday } from "date-fns/isToday"
import { omit } from "lodash-es"
import { sync } from "node-ical"

import type { MessageResponseEvents } from "../interfaces/message-response.js"

type EnvCalendar = {
  url: string
  provider: "google" | "outlook"
  type: "personal" | "work"
}

function getDaysArray(start: string, end: string) {
  const arr = []
  for (
    const dt = new Date(start);
    dt <= new Date(end);
    dt.setDate(dt.getDate() + 1)
  ) {
    arr.push(new Date(dt))
  }
  return arr
}

function commonParsing(event: any) {
  return {
    summary: event.summary,
    start: event.start.toISOString(),
    end: event.end ? event.end.toISOString() : null,
    confirmed: event.status === "CONFIRMED",
    startTime: event.start.toISOString().split("T")[1],
    endTime: event.end ? getTime(new Date(event.end)) : "",
    allDay: differenceInDays(event.end, event.start) > 1,
    dates: [...event.recurrences ? Object.keys(event.recurrences).map(key => new Date(key).toISOString()) : [], ...getDaysArray(
      event.start.toISOString(),
      event.end ? event.end.toISOString() : event.start.toISOString(),
    )],
  }
}

function todayEvents(events: any[]) {
  return events
    .filter(event => event.dates.some((date: string) => isToday(date)))
    .map(event => ({
      ...omit(event, ["dates"]),
    }))
}

async function getOutlookEvents(c: EnvCalendar) {
  const outlook = await fetch(c.url).then(rsp => rsp.text())

  const ical = sync.parseICS(outlook)
  const allEvents = Object.values(ical).filter(
    event => event.type === "VEVENT",
  )

  return todayEvents(
    allEvents.map(event => ({
      ...commonParsing(event),
      // @ts-expect-error exists on outlook
      allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
      calendar_type: c.type,
    })),
  )
}

async function getGmailEvents(c: EnvCalendar) {
  const calendar = await fetch(c.url).then(rsp => rsp.text())

  const ical = sync.parseICS(calendar)
  const allEvents = Object.values(ical).filter(
    event => event.type === "VEVENT",
  ) || []

  return todayEvents(
    allEvents.map(event => ({
      ...commonParsing(event),
      allDay: differenceInDays(event.end, event.start) > 1,
      calendar_type: c.type,
    })),
  )
}

function stripEmojis(str: string): string {
  return str
    .replace(
      /([\u2700-\u27BF\uE000-\uF8FF\u2011-\u26FF]|\uD83C[\uDC00-\uDFFF]|\uD83D[\uDC00-\uDFFF]|\uD83E[\uDD10-\uDDFF])/g,
      "",
    )
    .replace(/\s+/g, " ")
    .trim()
}

export async function getEvents(): Promise<MessageResponseEvents["events"]> {
  const calendars = JSON.parse(process.env.CALENDARS || "[]")
  const gmailEvents = (await Promise.all(((calendars as EnvCalendar[]).filter(calendar => calendar.provider === "google") || []).map(async calendar => getGmailEvents(calendar)))).flat()

  const outlookEvents = (await Promise.all(((calendars as EnvCalendar[]).filter(calendar => calendar.provider === "outlook") || []).map(async calendar => getOutlookEvents(calendar)))).flat()
  // .filter(e => isAfter(new Date(e.end), new Date()))
  return [...gmailEvents, ...outlookEvents].sort(
    (a, b) => new Date(a.start).getTime() - new Date(b.start).getTime(),
  ).map(event => ({
    ...event,
    summary: stripEmojis(event.summary).slice(0, 16),
    startTime: event.start ? format(new Date(event.start), "HH:mm") : null,
    endTime: event.end ? format(new Date(event.end), "HH:mm") : null,
    duration: event.end ? formatDistanceStrict(new Date(event.end), new Date(event.start)) : null,
  })).slice(0, 5) as unknown as MessageResponseEvents["events"]
}
