#pragma once

#include <base/types.h>
#include <common/IBuffer.h>

namespace MixS
{
class WriteBuffer : public IBuffer
{
public:
    WriteBuffer(BufferPtr buffer, SizeType size)
        : IBuffer(buffer, size)
    {
    }

    SizeType write(const void * src, SizeType size)
    {
        if (offset + size > data_size)
        {
            return;
        }
        std::memcpy(buffer + offset, src, size);
        offset += size;
        return size;
    }
};


} // namespace MixS
