"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getDateAndTime = void 0;
const date_fns_1 = require("date-fns");
const getDateAndTime = () => {
    return {
        date: (0, date_fns_1.format)(new Date(), "yyyy-MM-dd"),
        time: (0, date_fns_1.format)(new Date(), "HH:mm:ss"),
        hour: new Date().getHours(),
        minute: new Date().getMinutes(),
        second: new Date().getSeconds(),
        timezone: "Europe/London",
        utcOffset: 1,
        weekDay: new Date().getDay(),
        weekDayName: new Date().toLocaleString("en-US", { weekday: "long" }),
    };
};
exports.getDateAndTime = getDateAndTime;
//# sourceMappingURL=current.js.map