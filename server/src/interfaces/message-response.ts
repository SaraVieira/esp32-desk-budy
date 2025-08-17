export type MessageResponseIndex = {
  weather: {
    temperature: string
    description: string
    isDay: boolean
    apparentTemperature: string
    rain: boolean
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
    id: string
    title: string
    description?: string
    location?: string
    start: string
    end?: string
    confirmed: boolean
    startTime: string
    endTime?: string
    allDay: boolean
    dates?: string[]
  }[]
}
