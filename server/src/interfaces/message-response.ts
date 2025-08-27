export type MessageResponseIndex = {
  weather: {
    temperature: string
    description: string
    isDay: boolean
    apparentTemperature: string
    rain: boolean
    code: number
    tomorrow: {
      temperatureMax: string
      temperatureMin: string
      code: number
      description: string
    }
  }
  current: {
    date: string
    time: string
    hour: number
    minute: number
    second: number
    timezone: string
    utcOffset: number
    weekDay: number
    weekDayName: string
  }
}

export type MessageResponseEvents = {
  events: {
    id?: string
    title?: string
    description?: string
    location?: string
    start: string
    end?: string
    confirmed: boolean
    startTime: string
    endTime?: string
    allDay: boolean
    dates?: string[]
    duration: string | null
    summary: string

  }[]
}

export type MessageResponseNews = {
  news: {
    title: string
    link: string
    description: string
    published: string
  }[]
}
