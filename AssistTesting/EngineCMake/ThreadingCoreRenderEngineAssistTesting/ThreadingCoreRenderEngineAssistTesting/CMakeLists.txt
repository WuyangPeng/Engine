# CMakeList.txt: ThreadingCoreRenderEngineAssist 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../../Code/ThreadingCoreRenderEngineAssist/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
     add_library (ThreadingCoreRenderEngineAssistD SHARED ${SRC_DIR_LIST})
else()
     add_library (ThreadingCoreRenderEngineAssist SHARED ${SRC_DIR_LIST})
endif()  

# TODO: 如有需要，请添加测试并安装目标。
