cmake_minimum_required(VERSION 3.17)
project(project)

set(Boost_USE_STATIC_LIBS OFF)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(project src/main.cpp src/glad.c src/ElementBuffer.cpp src/ElementBuffer.h src/VertexBuffer.cpp src/VertexBuffer.h src/VertexArray.cpp src/VertexArray.h src/Shader_.h src/stb_image.h src/stb_image.cpp src/Sphere.cpp src/Sphere.h src/Shader.cpp src/Shader.h)

target_link_directories(project PRIVATE lib)
find_library(libglfw3.a glfw3 lib)
target_link_libraries(project -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl)