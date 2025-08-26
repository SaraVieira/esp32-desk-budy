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
async function getOutlookEvents(url) {
    const outlook = await fetch(url).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(outlook);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        // @ts-expect-error exists on outlook
        allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
    })));
}
async function getGmailEvents(url) {
    const calendar = await fetch(url).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(calendar);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        allDay: (0, date_fns_1.differenceInDays)(event.end, event.start) > 1,
    })));
}
async function getEvents() {
    const outlookEvents = (await Promise.all(JSON.parse(process.env.OUTLOOK_CALENDARS || `[]`).map(async (url) => getOutlookEvents(url)))).flat();
    const gmailEvents = (await Promise.all(JSON.parse(process.env.GMAIL_CALENDARS || `[]`).map(async (url) => getGmailEvents(url)))).flat();
    return [...gmailEvents, ...outlookEvents].sort((a, b) => new Date(a.start).getTime() - new Date(b.start).getTime()).map(event => ({
        ...event,
        startTime: event.start ? (0, date_fns_1.format)(new Date(event.start), "HH:mm") : null,
        endTime: event.end ? (0, date_fns_1.format)(new Date(event.end), "HH:mm") : null,
        duration: event.end ? (0, date_fns_1.formatDistanceStrict)(new Date(event.end), new Date(event.start)) : null,
    }));
}
//# sourceMappingURL=calendar.js.map