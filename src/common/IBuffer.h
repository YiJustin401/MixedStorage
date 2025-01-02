#pragma once

#include <base/types.h>
#include <memory>
#include <cstring>

namespace MixS
{
class IBuffer
{
public:
    using BufferPtr = void *;
    using SizeType = size_t;

    IBuffer(BufferPtr buffer, SizeType size)
        : buffer(buffer), data_size(size), offset(0)
    {
    }

    SizeType size() const
    {
        return data_size;
    }

    BufferPtr data() const
    {
        return buffer;
    }

protected:
    BufferPtr buffer;
    SizeType data_size;
    SizeType offset;
};


} // namespace MixS
