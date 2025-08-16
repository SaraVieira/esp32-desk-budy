import express from "express"
import type MessageResponse from "../interfaces/message-response.js"
import { getEvents } from "../lib/calendar.js"
import { getWeather } from "../lib/weather.js"
import { getDateAndTime } from "../lib/current.js"
import { format } from "date-fns"



const router = express.Router()


router.get<object, MessageResponse>("/", async (req, res) => {

const weather = await getWeather()
const events = await getEvents()

  const current = getDateAndTime()

res.json({
  current,
  weather,
  events,
})
})

export default router
