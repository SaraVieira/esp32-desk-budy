"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getSpotifyPlayer = getSpotifyPlayer;
exports.playSpotify = playSpotify;
exports.pauseSpotify = pauseSpotify;
exports.nextSpotify = nextSpotify;
exports.prevSpotify = prevSpotify;
const node_buffer_1 = require("node:buffer");
async function fetchToken() {
    return fetch("https://accounts.spotify.com/api/token", {
        method: "POST",
        headers: {
            "Authorization": `Basic ${node_buffer_1.Buffer.from(`${process.env.SPOTIFY_CLIENT_ID}:${process.env.SPOTIFY_CLIENT_SECRET}`).toString("base64")}`,
            "Content-Type": "application/x-www-form-urlencoded",
        },
        body: new URLSearchParams({
            grant_type: "refresh_token",
            refresh_token: process.env.SPOTIFY_REFRESH_TOKEN,
        }),
    });
}
async function getSpotifyPlayer() {
    // Token expired, refresh it
    return fetchToken().then(rsp => rsp.json()).then((data) => {
        return fetch("https://api.spotify.com/v1/me/player", {
            headers: {
                Authorization: `Bearer ${data.access_token}`,
            },
        }).then(rsp => rsp.json()).then((data) => {
            return {
                device: data.device,
                is_playing: data.is_playing,
                progress_ms: data.progress_ms,
                duration_ms: data.item.duration_ms,
                artists: data.item.artists.map((artist) => artist.name).join(", "),
                song: data.item.name,
                percentage: data.progress_ms && data.item.duration_ms ? Math.round((data.progress_ms / data.item.duration_ms) * 100) : 0,
            };
        }).catch(() => {
            return { closed: true };
        });
    });
}
async function playSpotify() {
    // Token expired, refresh it
    return fetchToken().then(rsp => rsp.json()).then((data) => {
        return fetch("https://api.spotify.com/v1/me/player/play", {
            method: "PUT",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${data.access_token}`,
            },
        });
    });
}
async function pauseSpotify() {
    // Token expired, refresh it
    return fetchToken().then(rsp => rsp.json()).then((data) => {
        return fetch("https://api.spotify.com/v1/me/player/pause", {
            method: "PUT",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${data.access_token}`,
            },
        });
    });
}
async function nextSpotify() {
    // Token expired, refresh it
    return fetchToken().then(rsp => rsp.json()).then((data) => {
        return fetch("https://api.spotify.com/v1/me/player/next", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${data.access_token}`,
            },
        });
    });
}
async function prevSpotify() {
    // Token expired, refresh it
    return fetchToken().then(rsp => rsp.json()).then((data) => {
        return fetch("https://api.spotify.com/v1/me/player/previous", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${data.access_token}`,
            },
        });
    });
}
//# sourceMappingURL=spotify.js.map