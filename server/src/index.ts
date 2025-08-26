import dotenv from "dotenv"

import app from "./app.js"

dotenv.config()

const port = process.env.PORT || 3000
const server = app.listen(port, () => {
  /* eslint-disable no-console */
  console.log(`Listening: http://localhost:${port}`)
  /* eslint-enable no-console */
})

server.on("error", (err) => {
  if ("code" in err && err.code === "EADDRINUSE") {
    console.error(
      `Port ${process.env.PORT} is already in use. Please choose another port or stop the process using it.`,
    )
  }
  else {
    console.error("Failed to start server:", err)
  }
  process.exit(1)
})
