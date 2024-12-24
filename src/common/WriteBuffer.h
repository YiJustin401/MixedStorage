#pragma once

#include <base/types.h>
#include <common/BufferBase.h>

namespace MixS
{
class WriteBuffer : public BufferBase
{
public:
    WriteBuffer(Position pos, SizeType size)
        : BufferBase(pos, size)
    {
    }

    void next()
    {
        if (!offset())
            return;
        
        SizeType bytes_in_buffer = offset();

        nextImpl();

        pos = working_set.begin();
    }

    void nextIfNotEnd()
    {
        if (available() > 0)
            next();
    }

    void write(const Position from, SizeType size)
    {
        SizeType bytes_written = 0;

        while (bytes_written < size)
        {
            SizeType bytes_to_write = std::min(size - bytes_written, SizeType(working_set.end() - pos));
            std::memcpy(pos, from + bytes_written, bytes_to_write);
            pos += bytes_to_write;
            bytes_written += bytes_to_write;
        }
    }

    void write(char c)
    {
        nextIfNotEnd();

        *pos = c;
        ++pos;
    }
private:
    virtual void nextImpl() { /** do nothing */ }


};


} // namespace MixS
