import express from "express"

import type { MessageResponseEvents, MessageResponseIndex } from "../interfaces/message-response.js"

import { getEvents } from "../lib/calendar.js"
import { getDateAndTime } from "../lib/current.js"
import { getWeather } from "../lib/weather.js"

const router = express.Router()

router.get<object, MessageResponseIndex>("/", async (req, res) => {
  const weather = await getWeather()
  const current = getDateAndTime()

  res.json({
    current,
    weather,
  })
})

router.get<object, MessageResponseEvents>("/events", async (req, res) => {
  const events = await getEvents()

  res.json({
    events,
  })
})

export default router
