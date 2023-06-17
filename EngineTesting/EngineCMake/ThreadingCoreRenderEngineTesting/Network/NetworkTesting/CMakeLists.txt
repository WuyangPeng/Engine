# CMakeList.txt: NetworkTesting 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../../Code/Network/NetworkTesting/*.cpp" "${CMAKE_SOURCE_DIR}/../../Code/Network/NetworkTesting/*.cc")

include_directories($ENV{EngineTestingInclude}/Network/NetworkTesting/NetworkMessageSuite/Detail) 

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
     add_executable (NetworkTestingD ${SRC_DIR_LIST})
else()
     add_executable (NetworkTesting ${SRC_DIR_LIST})
endif()

# TODO: 如有需要，请添加测试并安装目标。