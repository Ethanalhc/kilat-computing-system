cmake_minimum_required(VERSION 3.20)

project(Kilat)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME}
    src/main.c
    src/CPU/cpu.c
    src/CPU/Memory/memory.c
)

target_include_directories(${PROJECT_NAME} PRIVATE "include")