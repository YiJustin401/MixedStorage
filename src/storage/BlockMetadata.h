#pragma once

#include <time.h>

#include <base/types.h>

namespace MixS
{
class BlockMetadata
{
public:
    String block_id;
    u64 block_size;
    String checksum;
    time_t create_time;


    BlockMetadata() = default;

    static BlockMetadata getNull()
    {
        return BlockMetadata();
    }

    bool operator ==(const BlockMetadata &rhs) const
    {
        return block_id == rhs.block_id && block_size == rhs.block_size && checksum == rhs.checksum && create_time == rhs.create_time;
    }
};




} // namespace MixS
