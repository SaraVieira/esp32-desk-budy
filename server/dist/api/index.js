"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const calendar_js_1 = require("../lib/calendar.js");
const weather_js_1 = require("../lib/weather.js");
const current_js_1 = require("../lib/current.js");
const router = express_1.default.Router();
router.get("/", async (req, res) => {
    const weather = await (0, weather_js_1.getWeather)();
    const events = await (0, calendar_js_1.getEvents)();
    const current = (0, current_js_1.getDateAndTime)();
    res.json({
        current,
        weather,
        events,
    });
});
exports.default = router;
//# sourceMappingURL=index.js.map