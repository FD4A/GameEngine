cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
project(GameEngine)
add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra)

add_executable(GameEngine MAIN.cpp
						  ./Engine/Engine.cpp 						  
						  ./Render/RenderOpenGL_static.cpp
						  ./Render/RenderOpenGL.cpp
						  ./Render/ShadersOpenGL/ShaderOpenGL.cpp
						  ./Game/Game.cpp
						  ./Game/GameControl.cpp
						  ./Game/GameObject.cpp
						  ./ResourceManager/TextureManager.cpp
						  ./Audio/AudioManagerFMOD.cpp)
						  
target_link_libraries(GameEngine GL glfw fmod)
