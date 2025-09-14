import express from "express"

import type { MessageResponseEvents, MessageResponseIndex, MessageResponseNews, SpotifyPlayerRsp } from "../interfaces/message-response.js"

import { getEvents } from "../lib/calendar.js"
import { getDateAndTime } from "../lib/current.js"
import { getNews } from "../lib/news.js"
import { getSpotifyPlayer, nextSpotify, pauseSpotify, playSpotify, prevSpotify } from "../lib/spotify.js"
import { getWeather } from "../lib/weather.js"

const router = express.Router()

router.get<object, MessageResponseIndex>("/", async (_, res) => {
  const weather = await getWeather()
  const current = getDateAndTime()

  res.json({
    current,
    weather,
  })
})

router.get<object, MessageResponseEvents>("/events", async (_, res) => {
  const events = await getEvents()

  res.json({
    events,
  })
})

router.get<object, MessageResponseNews>("/news", async (_, res) => {
  const news = await getNews()

  res.json({
    news,
  })
})

router.get<object, SpotifyPlayerRsp>("/spotify/status", async (_, res) => {
  const status = await getSpotifyPlayer()
  res.json(status)
})

router.get<object, SpotifyPlayerRsp>("/spotify/play", async (_, res) => {
  await playSpotify()

  const status = await getSpotifyPlayer()

  res.json(status)
})

router.get<object, SpotifyPlayerRsp>("/spotify/pause", async (_, res) => {
  await pauseSpotify()

  const status = await getSpotifyPlayer()

  res.json(status)
})

router.get<object, SpotifyPlayerRsp>("/spotify/next", async (_, res) => {
  await nextSpotify()

  const status = await getSpotifyPlayer()

  res.json(status)
})

router.get<object, SpotifyPlayerRsp>("/spotify/prev", async (req, res) => {
  await prevSpotify()

  const status = await getSpotifyPlayer()

  res.json(status)
})

router.get<object, MessageResponseEvents>("/events-test", async (req, res) => {
  res.json({ events: [{ summary: "OOO - ️ 4 wk Sum", start: "2025-08-03T23:00:00.000Z", end: "2025-08-29T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "26 days" }, { summary: "Danuta is off (p", start: "2025-08-14T23:00:00.000Z", end: "2025-08-31T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "17 days" }, { summary: "Kristin Vacation", start: "2025-08-17T23:00:00.000Z", end: "2025-08-29T23:00:00.000Z", confirmed: true, startTime: "00:00", endTime: "00:00", allDay: true, calendar_type: "work", duration: "12 days" }, { summary: "Sara Vieira and ", start: "2025-08-29T14:00:00.000Z", end: "2025-08-29T14:30:00.000Z", confirmed: true, startTime: "15:00", endTime: "15:30", allDay: false, calendar_type: "personal", duration: "30 minutes" }] })
})

export default router
