import { format } from "date-fns"

export function getDateAndTime() {
  const offset = 1
  const UTCDate = new Date(
    Date.UTC(
      new Date().getUTCFullYear(),
      new Date().getUTCMonth(),
      new Date().getUTCDate(),
      new Date().getUTCHours(),
      new Date().getUTCMinutes(),
      new Date().getUTCSeconds()
    )
  )
  return {
    date: format(UTCDate, "iii dd/MM/yyyy"),
    time: format(UTCDate, "HH:mm:ss"),
    hour: UTCDate.getUTCHours() + offset,
    minute: UTCDate.getUTCMinutes(),
    second: UTCDate.getUTCSeconds(),
    timezone: "Europe/London",
    utcOffset: offset,
    weekDay: UTCDate.getUTCDay(),
    weekDayName: UTCDate.toLocaleString("en-US", {
      weekday: "long",
      timeZone: "UTC",
    }),
  }
}
