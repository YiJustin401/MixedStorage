#pragma once

#include <base/types.h>
#include <memory>
#include <cstring>

namespace MixS
{
class BufferBase
{
public:
    using Position = char *;
    using SizeType = size_t;
    class Buffer
    {
    public:
        Buffer(Position begin_pos_, Position end_pos_)
            : begin_pos(begin_pos)
            , end_pos(end_pos)
        {}
        Position & begin() { return begin_pos; }
        Position & end() { return end_pos; }
        SizeType size() const { return SizeType(end_pos - begin_pos);}

    private:
        Position begin_pos;
        Position end_pos;
    };

    BufferBase(Position buffer, SizeType size, SizeType offset = 0)
        : pos(buffer + offset)
        , working_set(pos, pos)
    {}

    SizeType offset() { return SizeType(pos - working_set.begin()); }
    SizeType available() { return SizeType(working_set.end() - pos); }

protected:
    Position pos;
    Buffer working_set;
}


} // namespace MixS
