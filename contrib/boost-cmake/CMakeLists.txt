# boost is a huge project, so we need to split it into multiple parts

SET (LIBRARY_DIR ${MixedStorage_SOURCE_DIR}/contrib/boost)

# ASIO
FILE (GLOB_RECURSE ASIO_SOURCES ${LIBRARY_DIR}/boost/libs/asio/include/boost/asio/*.hpp)