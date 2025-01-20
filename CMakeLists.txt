cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_C_COMPILER "clang")
# set(CMAKE_CXX_COMPILER "clang++")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

project(MixedStorage VERSION 0.0.1)

add_subdirectory(contrib)

include_directories(src)

file(GLOB_RECURSE SOURCES
    src/metadata/*.cpp
    src/network/*.cpp
    src/replication/*.cpp
    src/scheduler/*.cpp
    src/server/*.cpp
    src/server/*.h
    src/storage/*.cpp
)

add_executable(BTreeTest src/storage/test/main.cpp)
target_sources(BTreeTest PRIVATE ${SOURCES})
target_link_libraries(BTreeTest PUBLIC gtest_main boost_asio fmt)