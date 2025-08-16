import { format } from "date-fns"

export const getDateAndTime = () => {
  return {
    date: format(new Date(), "yyyy-MM-dd"),
    time: format(new Date(), "HH:mm:ss"),
    hour: new Date().getHours(),
    minute: new Date().getMinutes(),
    second: new Date().getSeconds(),
    timezone: "Europe/London",
    utcOffset: 1,
    weekDay: new Date().getDay(),
    weekDayName: new Date().toLocaleString("en-US", { weekday: "long" }),
  }
}
