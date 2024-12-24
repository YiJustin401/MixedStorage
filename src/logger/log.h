#pragma once

#include <fmt/core.h>
#include <fmt/chrono.h>

#include <base/types.h>
#include <utils/SingletonTemplate.h>
#include <chrono>

#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>
#include <unistd.h>

enum class LogLevel
{
    INFO,
    WARNING,
    ERROR
};

inline String levelToString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

/// impl logger
class Logger : public SingletonTemplate<Logger>
{
public:
    Logger()
    {
        log_stream.open(log_file, std::ios::app);
    }
    ~Logger()
    {
        log_stream.close();
    }

    void info(const String & message)
    {
        log(LogLevel::INFO, message);
    }
    
    void warning(const String & message)
    {
        log(LogLevel::WARNING, message);
    }

    void error(const String & message)
    {
        log(LogLevel::ERROR, message);
    }
private:
    void log(LogLevel level, const String & message)
    {
        if (level < log_level)
            return;

        std::stringstream ss;
        ss << getpid();
        // ss << std::this_thread::get_id();
        String current_time = fmt::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::system_clock::now());
        // String message = fmt::format(_log_fmt, std::forward<decltype(args)>(args)...);
        String log_message = fmt::format(log_fmt, current_time, ss.str(), "INFO", message);
        log_stream << log_message << std::endl;
        std::cout << log_message << std::endl;
    }

private:
    static constexpr const char* log_fmt = "{} [{}][{}]: {}";
    String log_file = "MixedStorage.log";
    LogLevel log_level = LogLevel::INFO;

    std::ofstream log_stream;
};
