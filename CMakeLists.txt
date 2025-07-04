cmake_minimum_required(VERSION 3.31)
project(Gungnir)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.8
)

FetchContent_MakeAvailable(glfw)
# --- End of GLFW section ---
add_library(glad lib/glad/src/glad.c)
target_include_directories(glad PUBLIC lib/glad/include)

add_executable(Gungnir src/main.cpp
        src/Engine.cpp
        src/Engine.h
        src/Window.cpp
        src/Window.h)


add_custom_target(CopyResources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/resources"
        "$<TARGET_FILE_DIR:Gungnir>/resources"
        COMMENT "Copying resources to build directory"
)
add_dependencies(Gungnir CopyResources)

# Link GLFW to your project
target_link_libraries(Gungnir PRIVATE glfw glad)
