"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.getNews = getNews;
const date_fns_1 = require("date-fns");
const rss_to_json_1 = __importDefault(require("rss-to-json"));
async function getNews() {
    const { items } = await (0, rss_to_json_1.default)("https://feeds.bbci.co.uk/news/rss.xml");
    return items.map(item => ({
        title: item.title,
        link: item.link,
        description: item.description,
        published: (0, date_fns_1.formatDistanceStrict)(new Date(item.published), new Date(), { addSuffix: true }),
    }));
}
//# sourceMappingURL=news.js.map