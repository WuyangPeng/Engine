# CMakeList.txt: AndroidCallBackUnitTestSuiteTesting 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.14)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    set(TARGET_PATH "${CMAKE_SOURCE_DIR}/../../Code/Framework/AndroidCallBackUnitTestSuiteTesting")

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    # 定义源路径和目标路径
    set(SOURCE_PATH "${CMAKE_SOURCE_DIR}/../../Code/Framework/AndroidCallBackUnitTestSuiteTesting")
    set(TARGET_PATH "${CMAKE_SOURCE_DIR}/../../../../Shortcuts")

    # 规范化路径
    get_filename_component(SOURCE_PATH "${SOURCE_PATH}" ABSOLUTE)
    get_filename_component(TARGET_PATH "${TARGET_PATH}" ABSOLUTE)

    # 清理目标路径（如果它存在）
    if (EXISTS "${TARGET_PATH}")
        message(STATUS "Removing existing path: ${TARGET_PATH}")
        file(REMOVE_RECURSE "${TARGET_PATH}")
    endif ()

    # 创建符号链接
    message(STATUS "Creating symlink from ${SOURCE_PATH} to ${TARGET_PATH}")
    file(CREATE_LINK "${SOURCE_PATH}" "${TARGET_PATH}" SYMBOLIC)

endif ()

file(GLOB_RECURSE SRC_DIR_LIST "${TARGET_PATH}/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_executable(AndroidCallBackUnitTestSuiteTestingD ${SRC_DIR_LIST})
else ()
    add_executable(AndroidCallBackUnitTestSuiteTesting ${SRC_DIR_LIST})
endif ()

# TODO: 如有需要，请添加测试并安装目标。