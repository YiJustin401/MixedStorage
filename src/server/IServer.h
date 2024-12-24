#pragma once

#include <base/types.h>

namespace MixS
{
class IServer
{
public:
    virtual ~IServer() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void config() = 0;
};

} // namespace MixS
