cmake_minimum_required(VERSION 3.0.0)
project(glfw_bug VERSION 0.1.0)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("libs/glfw-3.2.1/")

# Glad
add_subdirectory("libs/glad/")

add_executable(glfw_bug main.cpp)
target_link_libraries(glfw_bug PRIVATE glfw)
target_link_libraries(glfw_bug PRIVATE glad)