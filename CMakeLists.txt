cmake_minimum_required(VERSION 3.23)
project(masochism)

set(CMAKE_CXX_STANDARD 20)
link_libraries(ws2_32 wsock32)
add_executable(masochism main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
