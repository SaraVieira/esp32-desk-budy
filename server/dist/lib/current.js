"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getDateAndTime = getDateAndTime;
const date_fns_1 = require("date-fns");
function getDateAndTime() {
    const offset = 1;
    const UTCDate = new Date(Date.UTC(new Date().getUTCFullYear(), new Date().getUTCMonth(), new Date().getUTCDate(), new Date().getUTCHours(), new Date().getUTCMinutes(), new Date().getUTCSeconds()));
    const hour = UTCDate.getUTCHours() + offset;
    const minute = UTCDate.getUTCMinutes();
    const second = UTCDate.getUTCSeconds();
    return {
        date: (0, date_fns_1.format)(UTCDate, "iii dd/MM/yyyy"),
        time: (0, date_fns_1.format)(UTCDate, "HH:mm:ss"),
        hour,
        minute,
        second,
        separated: {
            eu: {
                hour: {
                    first: Math.floor(hour / 10),
                    second: hour % 10,
                },
                minute: {
                    first: Math.floor(minute / 10),
                    second: minute % 10,
                },
                second: {
                    first: Math.floor(second / 10),
                    second: second % 10,
                },
            },
        },
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