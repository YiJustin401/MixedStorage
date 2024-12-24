#pragma once

#include <base/types.h>

namespace MixS
{
class Storage
{
public:
    virtual ~Storage() = default;

    virtual void init() = 0;
    virtual void shutdown() = 0;

    virtual void writeBlock(u64 blockId, const u8* data, size_t size) = 0;
    virtual void readBlock(u64 blockId, u8* data, size_t size) = 0;
};

} // namespace MixS
