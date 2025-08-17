"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getWeather = getWeather;
const wmocodes_js_1 = require("./wmocodes.js");
async function getWeather() {
    const WEATHER_API_LINK = "https://api.open-meteo.com/v1/forecast?latitude=51.5085&longitude=-0.1257&daily=temperature_2m_max,temperature_2m_min,weather_code&models=ukmo_seamless&current=temperature_2m,is_day,apparent_temperature,rain,weather_code&timezone=auto&forecast_days=1";
    const data = await fetch(WEATHER_API_LINK).then(rsp => rsp.json());
    return {
        tomorrow: {
            temperatureMax: data.daily.temperature_2m_max[0] + data.daily_units.temperature_2m_max,
            temperatureMin: data.daily.temperature_2m_min[0] + data.daily_units.temperature_2m_min,
            code: data.daily.weather_code[0],
            description: wmocodes_js_1.WMO_CODES[data.daily.weather_code[0]].day.description,
        },
        temperature: data.current.temperature_2m + data.current_units.temperature_2m,
        description: wmocodes_js_1.WMO_CODES[data.current.weather_code][data.current.is_day ? "day" : "night"].description,
        isDay: data.current.is_day,
        apparentTemperature: data.current.apparent_temperature,
        rain: !!data.current.rain,
    };
}
//# sourceMappingURL=weather.js.map