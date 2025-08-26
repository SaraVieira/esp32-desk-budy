import { differenceInDays, format, formatDistanceStrict, getTime } from "date-fns"
import { isToday } from "date-fns/isToday"
import { omit } from "lodash-es"
import { sync } from "node-ical"

import type { MessageResponseEvents } from "../interfaces/message-response.js"

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
    dates: getDaysArray(
      event.start.toISOString(),
      event.end ? event.end.toISOString() : event.start.toISOString(),
    ),
  }
}

function todayEvents(events: any[]) {
  return events
    .filter(event => event.dates.some((date: string) => isToday(date)))
    .map(event => ({
      ...omit(event, ["dates"]),
    }))
}

async function getOutlookEvents(url: string) {
  const outlook = await fetch(url).then(rsp => rsp.text())

  const ical = sync.parseICS(outlook)
  const allEvents = Object.values(ical).filter(
    event => event.type === "VEVENT",
  )

  return todayEvents(
    allEvents.map(event => ({
      ...commonParsing(event),
      // @ts-expect-error exists on outlook
      allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
    })),
  )
}

async function getGmailEvents(url: string) {
  const calendar = await fetch(url).then(rsp => rsp.text())

  const ical = sync.parseICS(calendar)
  const allEvents = Object.values(ical).filter(
    event => event.type === "VEVENT",
  )

  return todayEvents(
    allEvents.map(event => ({
      ...commonParsing(event),
      allDay: differenceInDays(event.end, event.start) > 1,
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
  const gmailEvents = (await Promise.all((process.env.GMAIL_CALENDARS?.split(",") || []).map(async (url: string) => getGmailEvents(url)))).flat()
  const outlookEvents = (await Promise.all((process.env.OUTLOOK_CALENDARS?.split(",") || []).map(async (url: string) => getOutlookEvents(url)))).flat()

  return [...gmailEvents, ...outlookEvents].sort(
    (a, b) => new Date(a.start).getTime() - new Date(b.start).getTime(),
  ).map(event => ({
    ...event,
    summary: stripEmojis(event.summary),
    startTime: event.start ? format(new Date(event.start), "HH:mm") : null,
    endTime: event.end ? format(new Date(event.end), "HH:mm") : null,
    duration: event.end ? formatDistanceStrict(new Date(event.end), new Date(event.start)) : null,
  })) as unknown as MessageResponseEvents["events"]
}
