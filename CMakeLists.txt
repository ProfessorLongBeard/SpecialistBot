cmake_minimum_required(VERSION 3.22.1)

project(SP_Bot LANGUAGES C)


find_package(CURL REQUIRED)



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SP_TARGET "sp" CACHE STRING "")







add_executable(${SP_TARGET})

target_compile_options(${SP_TARGET} PRIVATE
    -Wall
    -Wextra
    -Wno-unused-parameter
    -Wno-unused-variable
    -Wno-unused-function
    -Wno-unused-but-set-variable
)

target_include_directories(${SP_TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${SP_TARGET} PRIVATE
    json-c
    discord
    CURL::libcurl
)

add_subdirectory(src)