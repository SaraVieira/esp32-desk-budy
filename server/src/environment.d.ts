declare global {
  namespace NodeJS {
    // eslint-disable-next-line ts/consistent-type-definitions
    interface ProcessEnv {
      OUTLOOK_CALENDARS?: string
      GMAIL_CALENDARS?: string
      NODE_ENV: "development" | "production"
      PORT?: string
      PWD: string
    }
  }
}

// If this file has no import/export statements (i.e. is a script)
// convert it into a module by adding an empty export statement.
export {}
