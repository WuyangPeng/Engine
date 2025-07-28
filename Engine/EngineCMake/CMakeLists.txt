# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.14)

project("ThreadingCoreRenderEngine")

# 引入路径配置文件
include(../../CMake/Include.cmake)

# 包含子项目。
add_subdirectory("System")

add_subdirectory("CoreTools")

add_subdirectory("Network")
add_subdirectory("Database")
add_subdirectory("Script")
add_subdirectory("Mathematics")
add_subdirectory("SoundEffect")
add_subdirectory("InputOutput")

add_subdirectory("ResourceManager")
add_subdirectory("Rendering")
add_subdirectory("Physics")
add_subdirectory("Imagics")

add_subdirectory("Animation")
add_subdirectory("ArtificialIntelligence")
add_subdirectory("UserInterface")

add_subdirectory("AssistTools")

add_subdirectory("Framework")

add_subdirectory("ThreadingCoreRenderEngine")