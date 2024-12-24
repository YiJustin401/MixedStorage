#pragma once

#include <exception>
#include <base/types.h>

class Exception : public std::exception
{
public:
    Exception(const String& message) : message(message) {}

    const String getMessage() const { return message + what(); }

private:
    String message;
};

