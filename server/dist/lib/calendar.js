"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.getEvents = getEvents;
const date_fns_1 = require("date-fns");
const isToday_1 = require("date-fns/isToday");
const lodash_es_1 = require("lodash-es");
const node_ical_1 = require("node-ical");
const calendar_json_1 = __importDefault(require("../calendar.json"));
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
        dates: [...event.recurrences ? Object.keys(event.recurrences).map(key => new Date(key).toISOString()) : [], ...getDaysArray(event.start.toISOString(), event.end ? event.end.toISOString() : event.start.toISOString())],
    };
}
function todayEvents(events) {
    return events
        .filter(event => event.dates.some((date) => (0, isToday_1.isToday)(date)))
        .map(event => ({
        ...(0, lodash_es_1.omit)(event, ["dates"]),
    }));
}
async function getOutlookEvents(c) {
    const outlook = await fetch(c.url).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(outlook);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT");
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        // @ts-expect-error exists on outlook
        allDay: event["MICROSOFT-CDO-ALLDAYEVENT"].toLowerCase() === "true",
        calendar_type: c.type,
    })));
}
async function getGmailEvents(c) {
    const calendar = await fetch(c.url).then(rsp => rsp.text());
    const ical = node_ical_1.sync.parseICS(calendar);
    const allEvents = Object.values(ical).filter(event => event.type === "VEVENT") || [];
    return todayEvents(allEvents.map(event => ({
        ...commonParsing(event),
        allDay: (0, date_fns_1.differenceInDays)(event.end, event.start) > 1,
        calendar_type: c.type,
    })));
}
function stripEmojis(str) {
    return str
        .replace(/([\u2700-\u27BF\uE000-\uF8FF\u2011-\u26FF]|\uD83C[\uDC00-\uDFFF]|\uD83D[\uDC00-\uDFFF]|\uD83E[\uDD10-\uDDFF])/g, "")
        .replace(/\s+/g, " ")
        .trim();
}
async function getEvents() {
    const gmailEvents = (await Promise.all((calendar_json_1.default.filter(calendar => calendar.provider === "google") || []).map(async (calendar) => getGmailEvents(calendar)))).flat();
    const outlookEvents = (await Promise.all((calendar_json_1.default.filter(calendar => calendar.provider === "outlook") || []).map(async (calendar) => getOutlookEvents(calendar)))).flat();
    return [...gmailEvents, ...outlookEvents].filter(e => (0, date_fns_1.isAfter)(new Date(e.end), new Date())).sort((a, b) => new Date(a.start).getTime() - new Date(b.start).getTime()).map(event => ({
        ...event,
        summary: stripEmojis(event.summary).slice(0, 16),
        startTime: event.start ? (0, date_fns_1.format)(new Date(event.start), "HH:mm") : null,
        endTime: event.end ? (0, date_fns_1.format)(new Date(event.end), "HH:mm") : null,
        duration: event.end ? (0, date_fns_1.formatDistanceStrict)(new Date(event.end), new Date(event.start)) : null,
    })).slice(0, 5);
}
//# sourceMappingURL=calendar.js.map