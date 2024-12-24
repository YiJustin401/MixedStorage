cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(MyProject VERSION 1.0)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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