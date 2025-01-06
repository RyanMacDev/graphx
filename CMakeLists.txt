cmake_minimum_required(VERSION 3.10)
project(GraphicsEngine)

set(CMAKE_CXX_STANDARD 17)

# Manually specify GLEW paths
set(GLEW_INCLUDE_DIR /usr/include/GL)
set(GLEW_LIBRARY /usr/lib/x86_64-linux-gnu/libGLEW.so)

# Manually specify GLFW paths
set(GLFW_INCLUDE_DIR /usr/include/GLFW)
set(GLFW_LIBRARY /usr/lib/x86_64-linux-gnu/libglfw.so)

# Manually specify OpenGL path (optional, typically auto-detected)
find_package(OpenGL REQUIRED)
set(OPENGL_LIBRARY /usr/lib/x86_64-linux-gnu/libGL.so)

# Add include directories for GLEW and GLFW
include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})

# Include directories
include_directories(include)

# Add all source files to the project
add_executable(GraphicsEngine
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
)

target_link_libraries(GraphicsEngine ${GLEW_LIBRARY} ${GLFW_LIBRARY} ${OPENGL_LIBRARY})

