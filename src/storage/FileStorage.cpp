#include <fcntl.h>

#include <common/Exception.h>
#include <FileStorage.h>


namespace MixS
{
FileStorage::FileStorage(const String& filename)
{
    file_descriptor = open(filename.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (file_descriptor == -1)
    {
        throw Exception("Failed to open file");
    }

    /// @todo Implement this
}

FileStorage::~FileStorage()
{
    close(file_descriptor);
}

void FileStorage::init()
{
    /// @todo Implement this
}

void FileStorage::shutdown()
{
    /// @todo Implement this
}

void FileStorage::writeBlock(u64 blockId, const u8* data, size_t size)
{
    /// @todo Implement this
}

void FileStorage::readBlock(u64 blockId, u8* data, size_t size)
{
    /// @todo Implement this
}

} // namespace MixS
