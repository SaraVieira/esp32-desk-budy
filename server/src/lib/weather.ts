import MessageResponse from "../interfaces/message-response"
import { WMO_CODES } from "./wmocodes"

export const getWeather = async (): Promise<MessageResponse["weather"]> => {
  const WEATHER_API_LINK =
    "https://api.open-meteo.com/v1/forecast?latitude=51.6006521&longitude=-0.1029245&models=ukmo_seamless&current=temperature_2m,is_day,rain,apparent_temperature,weather_code&forecast_days=1"
  const data = await fetch(WEATHER_API_LINK).then((rsp) => rsp.json())

  return {
    temperature:
      data.current.temperature_2m + data.current_units.temperature_2m,
    description:
    // @ts-expect-error
      WMO_CODES[data.current.weather_code][
        data.current.is_day ? "day" : "night"
      ].description,
    isDay: data.current.is_day,
    apparentTemperature: data.current.apparent_temperature,
    rain: data.current.rain ? true : false,
  }
}
