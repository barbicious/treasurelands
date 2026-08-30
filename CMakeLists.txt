cmake_minimum_required(VERSION 4.3)
project(treasurelands C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG master
)

FetchContent_MakeAvailable(glfw)

add_executable(treasurelands src/main.c src/util/list.h
        src/util/types.h
        src/core/window.c
        src/core/window.h
        src/util/string.h
        src/util/string.c
        vendor/glad/src/glad.c
        src/context.c
        src/context.h
)

target_link_libraries(treasurelands PRIVATE glfw)

target_include_directories(treasurelands PRIVATE vendor/glad/include)