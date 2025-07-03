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

add_executable(Gungnir src/main.cpp)
# Link GLFW to your project
target_link_libraries(Gungnir PRIVATE glfw)
