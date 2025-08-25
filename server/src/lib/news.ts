import { formatDistanceStrict } from "date-fns"
import parse from "rss-to-json"

import type { MessageResponseNews } from "../interfaces/message-response.js"

export async function getNews(): Promise<MessageResponseNews["news"]> {
  const { items } = await parse("https://feeds.bbci.co.uk/news/rss.xml")

  return items.map(item => ({
    title: item.title,
    link: item.link,
    description: item.description,
    published: formatDistanceStrict(new Date(item.published), new Date(), { addSuffix: true }),
  }))
}
