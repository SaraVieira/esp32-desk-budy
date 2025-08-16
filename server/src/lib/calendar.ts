import { sync } from "node-ical"
import { isToday } from "date-fns/isToday"
import { omit } from "lodash-es"
import { differenceInDays, getTime } from "date-fns"
import MessageResponse from "../interfaces/message-response"

const getDaysArray = function (start: string, end: string) {
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

const OUTLOOK =
  "https://outlook.office365.com/owa/calendar/f91efcaebd264b3ea3037db22dcb1797@epilot.cloud/7f0f9264bf1845bf89bea86b74aca63110921515895800548356/calendar.ics"
const CALENDAR =
  "https://calendar.google.com/calendar/ical/hey%40iamsaravieira.com/public/basic.ics"
const BENFICA_CALENDAR =
  "https://calendar.google.com/calendar/ical/spducgnrp5ph8lmsceg7c7f8p0%40group.calendar.google.com/public/basic.ics"

const commonParsing = (event: any) => ({
  summary: event.summary,
  start: event.start.toISOString(),
  end: event.end ? event.end.toISOString() : null,
  confirmed: event.status === "CONFIRMED",
  startTime: event.start.toISOString().split("T")[1],
  endTime: event.end ? getTime(new Date(event.end)) : "",
  allDay: differenceInDays(event.end, event.start) > 1,
  dates: getDaysArray(
    event.start.toISOString(),
    event.end ? event.end.toISOString() : event.start.toISOString()
  ),
})

const todayEvents = (events: any[]) =>
  events
    .filter((event) => event.dates.some((date: string) => isToday(date)))
    .map((event) => ({
      ...omit(event, ["dates"]),
    }))

const getOutlookEvents = async () => {
  const outlook = await fetch(OUTLOOK).then((rsp) => rsp.text())

  const ical = sync.parseICS(outlook)
  const allEvents = Object.values(ical).filter(
    (event) => event.type === "VEVENT"
  )

  return todayEvents(
    allEvents.map((event) => ({
      ...commonParsing(event),
      // @ts-expect-error
      allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
    }))
  )
}

const getCalendarEvents = async () => {
  const calendar = await fetch(CALENDAR).then((rsp) => rsp.text())

  const ical = sync.parseICS(calendar)
  const allEvents = Object.values(ical).filter(
    (event) => event.type === "VEVENT"
  )

  return todayEvents(
    allEvents.map((event) => ({
      ...commonParsing(event),
      allDay: differenceInDays(event.end, event.start) > 1,
    }))
  )
}

const getBenficaEvents = async () => {
  const calendar = await fetch(BENFICA_CALENDAR).then((rsp) => rsp.text())

  const ical = sync.parseICS(calendar)
  const allEvents = Object.values(ical).filter(
    (event) => event.type === "VEVENT"
  )

  return todayEvents(
    allEvents.map((event) => ({
      ...commonParsing(event),
      allDay: differenceInDays(event.end, event.start) > 1,
    }))
  )
}

export const getEvents = async (): Promise<MessageResponse["events"]> => {
  const outlookEvents = await getOutlookEvents()
  const calendarEvents = await getCalendarEvents()
  const benficaEvents = await getBenficaEvents()

  return [
      ...calendarEvents,
      ...outlookEvents,
      ...benficaEvents,
    ].sort((a, b) => new Date(a.start).getTime() - new Date(b.start).getTime()) as MessageResponse["events"]

}

