cmake_minimum_required(VERSION 4.3)
project(treasurelands C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG master
)

FetchContent_Declare(
        cglm
        GIT_REPOSITORY https://github.com/recp/cglm
        GIT_TAG master
)

FetchContent_MakeAvailable(glfw cglm)

add_executable(treasurelands src/main.c src/util/list.h
        src/util/types.h
        src/core/window.c
        src/core/window.h
        src/util/string.h
        src/util/string.c
        vendor/glad/src/glad.c
        src/context.c
        src/context.h
        src/gfx/shader.c
        src/gfx/shader.h
        src/gfx/vao.c
        src/gfx/vao.h
        src/gfx/vbo.c
        src/gfx/vbo.h
        src/gfx/texture.c
        src/gfx/texture.h
        src/core/camera.c
        src/core/camera.h
        src/lvl/tile.c
        src/lvl/tile.h
        src/lvl/chunk_mesh.c
        src/lvl/chunk_mesh.h
)

add_custom_command(TARGET treasurelands POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        $<TARGET_FILE_DIR:treasurelands>/res
)

target_link_libraries(treasurelands PRIVATE glfw cglm)

target_include_directories(treasurelands PRIVATE vendor/glad/include vendor)