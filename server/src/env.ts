import { z } from "zod/v4";

const envSchema = z.object({
  NODE_ENV: z.enum(["development", "production", "test"]).default("production").optional(),
  PORT: z.coerce.number().default(3000),
});



// eslint-disable-next-line node/no-process-env
export const env = envSchema.parse(process.env);
