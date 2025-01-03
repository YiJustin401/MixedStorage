#pragma once

#include <base/types.h>
#include <common/BufferBase.h>

namespace MixS
{
class ReadBuffer : public BufferBase
{
public:
    ReadBuffer(Position buffer, SizeType size)
        : BufferBase(buffer, size)
    {
    }

    bool next()
    {
        bool res = nextImpl();
        next_working_set_bytes = 0;
        return res;
    }

    bool eof()
    {
        return !next();
    }

    SizeType read(void * dest, SizeType size)
    {
        SizeType byties_copied = 0;
        while (byties_copied < size && !eof())
        {
            SizeType bytes_to_copy = std::min(size - byties_copied, SizeType(working_set.end() - pos));
            std::memcpy(dest + byties_copied, pos, bytes_to_copy);
            pos += bytes_to_copy;
            byties_copied += bytes_to_copy;
        }
        return byties_copied;
    }
protected:
    SizeType next_working_set_bytes = 0;

private:
    /// @brief read next data into the buffer
    /// @return read failed or not
    virtual bool nextImpl()
    {
        return false;
    }
};




} // namespace MixS
