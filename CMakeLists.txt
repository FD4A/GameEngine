cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
project(GameEngine)
add_compile_options(-std=c++20)

add_executable(GameEngine MAIN.cpp
						  Image.cpp
						  Scene.cpp
						  GameObject.cpp)
