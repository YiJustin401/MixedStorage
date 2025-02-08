cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_C_COMPILER "clang")
# set(CMAKE_CXX_COMPILER "clang++")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

project(MixedStorage VERSION 0.0.1)

add_subdirectory(contrib)
include(cmake/gtest.cmake)
include(cmake/include.cmake)

include_directories(src)

file(GLOB_RECURSE SOURCES
    src/metadata/*.cpp
    src/network/*.cpp
    src/replication/*.cpp
    src/scheduler/*.cpp
    src/server/*.cpp
    src/server/*.h
    src/storage/*.cpp
    src/utils/*.h
    src/utils/*.cpp
)
# remove gtest files
list(FILTER SOURCES EXCLUDE REGEX ".*gtest_.*")

add_library(mixed_storage_lib STATIC ${SOURCES})
target_link_libraries(mixed_storage_lib PUBLIC boost_asio fmt)

option(ENABLE_TEST "Enable test" ON)
if (ENABLE_TEST)
    GTEST_SOURCES(src/storage/test/gtest_BTreeTest.cpp)
    GTEST_SOURCES(src/utils/test/gtest_threadpool.cpp)
    MIXED_EXECUTE_BINARY(mixed_storage_test "${gtest_source_files}" gtest_main)
endif()

MIXED_EXECUTE_BINARY(mixed_metadata_server src/programs/MixedMetadataServer.cpp "")
MIXED_EXECUTE_BINARY(mixed_storage_server src/programs/MixedStorageServer.cpp "")
