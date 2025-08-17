"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getEvents = getEvents;
const date_fns_1 = require("date-fns");
const isToday_1 = require("date-fns/isToday");
const lodash_es_1 = require("lodash-es");
const node_ical_1 = require("node-ical");
function getDaysArray(start, end) {
    const arr = [];
    for (const dt = new Date(start); dt <= new Date(end); dt.setDate(dt.getDate() + 1)) {
        arr.push(new Date(dt));
    }
    return arr;
}
const OUTLOOK = "https://outlook.office365.com/owa/calendar/f91efcaebd264b3ea3037db22dcb1797@epilot.cloud/7f0f9264bf1845bf89bea86b74aca63110921515895800548356/calendar.ics";
const CALENDAR = "https://calendar.google.com/calendar/ical/hey%40iamsaravieira.com/public/basic.ics";
const BENFICA_CALENDAR = "https://calendar.google.com/calendar/ical/spducgnrp5ph8lmsceg7c7f8p0%40group.calendar.google.com/public/basic.ics";
function commonParsing(event) {
    return {
        summary: event.summary,
        start: event.start.toISOString(),
        end: event.end ? event.end.toISOString() : null,
        confirmed: event.status === "CONFIRMED",
        startTime: event.start.toISOString().split("T")[1],
        endTime: event.end ? (0, date_fns_1.getTime)(new Date(event.end)) : "",
        allDay: (0, date_fns_1.differenceInDays)(event.end, event.start) > 1,
        dates: getDaysArray(event.start.toISOString(), event.end ? event.end.toISOString() : event.start.toISOString()),
    };
}
function todayEvents(events) {
    return events
        .filter(event => event.dates.some((date) => (0, isToday_1.isToday)(date)))
        .map(event => ({
        ...(0, lodash_es_1.omit)(event, ["dates"]),
    }));
}
async function getOutlookEvents() {
    const outlook = await fetch(OUTLOOK).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(outlook);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        // @ts-expect-error exists on outlook
        allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
    })));
}
async function getCalendarEvents() {
    const calendar = await fetch(CALENDAR).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(calendar);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        allDay: (0, date_fns_1.differenceInDays)(event.end, event.start) > 1,
    })));
}
async function getBenficaEvents() {
    const calendar = await fetch(BENFICA_CALENDAR).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(calendar);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        allDay: (0, date_fns_1.differenceInDays)(event.end, event.start) > 1,
    })));
}
async function getEvents() {
    const outlookEvents = await getOutlookEvents();
    const calendarEvents = await getCalendarEvents();
    const benficaEvents = await getBenficaEvents();
    return [
        ...calendarEvents,
        ...outlookEvents,
        ...benficaEvents,
    ].sort((a, b) => new Date(a.start).getTime() - new Date(b.start).getTime());
}
//# sourceMappingURL=calendar.js.map