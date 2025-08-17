"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getDateAndTime = getDateAndTime;
const date_fns_1 = require("date-fns");
function getDateAndTime() {
    const offset = 1;
    const UTCDate = new Date(Date.UTC(new Date().getUTCFullYear(), new Date().getUTCMonth(), new Date().getUTCDate(), new Date().getUTCHours(), new Date().getUTCMinutes(), new Date().getUTCSeconds()));
    return {
        date: (0, date_fns_1.format)(UTCDate, "iii dd/MM/yyyy"),
        time: (0, date_fns_1.format)(UTCDate, "HH:mm:ss"),
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
    };
}
//# sourceMappingURL=current.js.map