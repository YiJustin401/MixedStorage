cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

project(MixedStorage VERSION 0.0.1)

add_subdirectory(contrib)

include_directories(contrib/googletest/googletest/include)

#boost asio
include_directories(contrib/boost/libs/asio/include)

include_directories(src)

file(GLOB_RECURSE SOURCES
    src/metadata/*.cpp
    src/network/*.cpp
    src/replication/*.cpp
    src/scheduler/*.cpp
    src/storage/*.cpp
)

add_executable(BTreeTest src/storage/test/main.cpp)
target_sources(BTreeTest PRIVATE ${SOURCES})
target_link_libraries(BTreeTest gtest_main)