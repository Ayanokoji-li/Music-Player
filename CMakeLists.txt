cmake_minimum_required(VERSION 3.22)

project(MusicPlayer LANGUAGES CXX VERSION 1.0)

add_definitions(-DDEBUG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(CMAKE_CXXCOMPILER "clang++")
file(GLOB CORE "src/core/*.cpp")
add_library(CoreLib ${CORE})

file(GLOB UTILS "src/utils/*.cpp")
add_library(UtilsLib ${UTILS})

add_executable(MusicPlayer src/main.cpp)

target_include_directories(MusicPlayer PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(MusicPlayer CoreLib)
target_link_libraries(MusicPlayer UtilsLib)