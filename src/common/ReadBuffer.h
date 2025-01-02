#pragma once

#include <base/types.h>
#include <common/IBuffer.h>

namespace MixS
{
class ReadBuffer : public IBuffer
{
public:
    ReadBuffer(BufferPtr buffer, SizeType size)
        : IBuffer(buffer, size)
    {
    }

    SizeType read(void * dest, SizeType size)
    {
        if (offset + size > data_size)
        {
            return;
        }
        std::memcpy(dest, buffer + offset, size);
        offset += size;
        return size;
    }
};




} // namespace MixS
