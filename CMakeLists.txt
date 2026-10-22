cmake_minimum_required(VERSION 3.10)
project(MiniVecDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(minivecdb src/main.cpp src/CommandParser.cpp src/StorageEngine.cpp)

add_executable(test_kv tests/test_kv.cpp src/CommandParser.cpp src/StorageEngine.cpp)