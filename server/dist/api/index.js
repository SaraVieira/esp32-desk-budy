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
exports.default = router;
//# sourceMappingURL=index.js.map