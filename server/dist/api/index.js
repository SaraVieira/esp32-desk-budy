"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const calendar_js_1 = require("../lib/calendar.js");
const current_js_1 = require("../lib/current.js");
const news_js_1 = require("../lib/news.js");
const weather_js_1 = require("../lib/weather.js");
const router = express_1.default.Router();
router.get("/", async (req, res) => {
    const weather = await (0, weather_js_1.getWeather)();
    const current = (0, current_js_1.getDateAndTime)();
    res.json({
        current,
        weather,
    });
});
router.get("/events", async (req, res) => {
    const events = await (0, calendar_js_1.getEvents)();
    res.json({
        events,
    });
});
router.get("/news", async (req, res) => {
    const news = await (0, news_js_1.getNews)();
    res.json({
        news,
    });
});
router.get("/events-test", async (req, res) => {
    res.json({ events: [{ summary: "OOO - ️ 4 wk Summer Holidays w/ the Family", start: "2025-08-04T00:00:00.000Z", end: "2025-08-30T00:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, duration: "26 days" }, { summary: "Danuta is off (public holidays + vacation) ‍️", start: "2025-08-15T00:00:00.000Z", end: "2025-09-01T00:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, duration: "17 days" }, { summary: "Kristin Vacation", start: "2025-08-18T00:00:00.000Z", end: "2025-08-30T00:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, duration: "12 days" }, { summary: "Busy", start: "2025-08-27T11:00:00.000Z", end: "2025-08-27T12:00:00.000Z", confirmed: false, startTime: "11:00", endTime: "12:00", allDay: false, duration: "1 hour" }, { summary: "Busy", start: "2025-08-27T14:30:00.000Z", end: "2025-08-27T17:15:00.000Z", confirmed: false, startTime: "14:30", endTime: "17:15", allDay: false, duration: "3 hours" }, { summary: "Benfica - Fenerbahçe [CL]", start: "2025-08-27T19:00:00.000Z", end: "2025-08-27T20:45:00.000Z", confirmed: true, startTime: "19:00", endTime: "20:45", allDay: false, duration: "2 hours" }] });
});
exports.default = router;
//# sourceMappingURL=index.js.map