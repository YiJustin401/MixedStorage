#pragma once

#include <logger/log.h>

#define LOG_INFO(log_fmt, ...) Logger::getInstance().info(fmt::format(log_fmt, ##__VA_ARGS__))
#define LOG_WARNING(log_fmt, ...) Logger::getInstance().warning(fmt::format(log_fmt, ##__VA_ARGS__))
#define LOG_ERROR(log_fmt, ...) Logger::getInstance().error(fmt::format(log_fmt, ##__VA_ARGS__))

