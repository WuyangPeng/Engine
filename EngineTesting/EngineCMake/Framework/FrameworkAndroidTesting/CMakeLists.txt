# CMakeList.txt: FrameworkAndroidTesting 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../Code/Framework/FrameworkAndroidTesting/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_executable(FrameworkAndroidTestingD ${SRC_DIR_LIST})
else ()
    add_executable(FrameworkAndroidTesting ${SRC_DIR_LIST})
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(DESTINATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../x64/CMake/DebugWindows/Configuration)

    else ()

        set(DESTINATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../x64/CMake/ReleaseWindows/Configuration)

    endif ()

    set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../EngineWindows/Framework/FrameworkAndroidTesting/Configuration/FrameworkAndroidTesting.json)

    message("CopyFrom: ${SOURCE_PATH}")
    message("CopyTo: ${DESTINATION_PATH}")
    file(COPY ${SOURCE_PATH}/ DESTINATION ${DESTINATION_PATH})

endif ()

# TODO: 如有需要，请添加测试并安装目标。
