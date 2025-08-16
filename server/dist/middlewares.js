"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.notFound = notFound;
exports.errorHandler = errorHandler;
const env_js_1 = require("./env.js");
function notFound(req, res, next) {
    res.status(404);
    const error = new Error(`🔍 - Not Found - ${req.originalUrl}`);
    next(error);
}
function errorHandler(err, req, res, _next) {
    const statusCode = res.statusCode !== 200 ? res.statusCode : 500;
    res.status(statusCode);
    res.json({
        message: err.message,
        stack: env_js_1.env.NODE_ENV === "production" ? "🥞" : err.stack,
    });
}
//# sourceMappingURL=middlewares.js.map