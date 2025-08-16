"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.env = void 0;
const v4_1 = require("zod/v4");
const envSchema = v4_1.z.object({
    NODE_ENV: v4_1.z.enum(["development", "production", "test"]).default("production").optional(),
    PORT: v4_1.z.coerce.number().default(3000),
});
// eslint-disable-next-line node/no-process-env
exports.env = envSchema.parse(process.env);
//# sourceMappingURL=env.js.map