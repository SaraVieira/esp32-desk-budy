"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const calendar_js_1 = require("../lib/calendar.js");
const current_js_1 = require("../lib/current.js");
const news_js_1 = require("../lib/news.js");
const spotify_js_1 = require("../lib/spotify.js");
const weather_js_1 = require("../lib/weather.js");
const router = express_1.default.Router();
router.get("/", async (_, res) => {
    const weather = await (0, weather_js_1.getWeather)();
    const current = (0, current_js_1.getDateAndTime)();
    res.json({
        current,
        weather,
    });
});
router.get("/events/all", async (_, res) => {
    const events = await (0, calendar_js_1.getAllEvents)();
    res.json({
        events,
    });
});
router.get("/events", async (_, res) => {
    const events = await (0, calendar_js_1.getEvents)();
    res.json({
        events,
    });
});
router.get("/news", async (_, res) => {
    const news = await (0, news_js_1.getNews)();
    res.json({
        news,
    });
});
router.get("/spotify/status", async (_, res) => {
    const status = await (0, spotify_js_1.getSpotifyPlayer)();
    res.json(status);
});
router.get("/spotify/play", async (_, res) => {
    await (0, spotify_js_1.playSpotify)();
    const status = await (0, spotify_js_1.getSpotifyPlayer)();
    res.json(status);
});
router.get("/spotify/pause", async (_, res) => {
    await (0, spotify_js_1.pauseSpotify)();
    const status = await (0, spotify_js_1.getSpotifyPlayer)();
    res.json(status);
});
router.get("/spotify/next", async (_, res) => {
    await (0, spotify_js_1.nextSpotify)();
    const status = await (0, spotify_js_1.getSpotifyPlayer)();
    res.json(status);
});
router.get("/spotify/prev", async (req, res) => {
    await (0, spotify_js_1.prevSpotify)();
    const status = await (0, spotify_js_1.getSpotifyPlayer)();
    res.json(status);
});
router.get("/events-test", async (req, res) => {
    res.json({ events: [{ summary: "OOO - ️ 4 wk Sum", start: "2025-08-03T23:00:00.000Z", end: "2025-08-29T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "26 days" }, { summary: "Danuta is off (p", start: "2025-08-14T23:00:00.000Z", end: "2025-08-31T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "17 days" }, { summary: "Kristin Vacation", start: "2025-08-17T23:00:00.000Z", end: "2025-08-29T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "12 days" }, { summary: "Sara Vieira and ", start: "2025-08-29T14:00:00.000Z", end: "2025-08-29T14:30:00.000Z", confirmed: true, startTime: "15:00", endTime: "15:30", allDay: false, calendar_type: "personal", duration: "30 minutes" }] });
});
exports.default = router;
//# sourceMappingURL=index.js.map