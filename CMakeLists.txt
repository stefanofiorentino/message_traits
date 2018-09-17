cmake_minimum_required(VERSION 3.12)
project(message_traits)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(libs)
include_directories(libs/dispatcher)
include_directories(libs/dispatcher/include)

add_executable(message_traits
        libs/dispatcher/include/message_traits.hpp
        libs/dispatcher/notifier.hpp src/main.cpp)
