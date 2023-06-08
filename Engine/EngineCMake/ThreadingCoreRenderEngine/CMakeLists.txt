# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("ThreadingCoreRenderEngine")

set(CMAKE_CXX_STANDARD 20)

include_directories($ENV{LibsEnvironmentBaseInclude}/)
include_directories($ENV{LibsEnvironmentExtendInclude}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Code)

if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

    link_directories($ENV{LibsEnvironmentX64DebugLib}/)   
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows) 

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows)

else()

    link_directories($ENV{LibsEnvironmentX64ReleaseLib}/) 
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows) 

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows)

endif()  
 
link_directories($ENV{LibsEnvironmentX64Lib}/)

# 包含子项目。
add_subdirectory ("System")
add_subdirectory ("CoreTools")
add_subdirectory ("Network")
add_subdirectory ("Database")
add_subdirectory ("Script")
add_subdirectory ("Mathematics")

add_subdirectory ("ThreadingCoreRenderEngine")
