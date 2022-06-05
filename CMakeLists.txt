cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
project(GameEngine)
add_compile_options(-std=c++20)

add_executable(GameEngine MAIN.cpp
						  ./ResourceManager/Image.cpp
						  ./Render/RenderOpenGL_static.cpp
						  ./Render/RenderOpenGL.cpp
						  ./Render/ShadersOpenGL/ShaderOpenGL.cpp
						  ./Game/Scene.cpp
						  ./Game/GameObject.cpp)
						  
target_link_libraries(GameEngine GL glfw)
