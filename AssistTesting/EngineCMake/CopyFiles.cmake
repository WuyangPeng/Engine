# CopyFiles.cmake
cmake_minimum_required(VERSION 3.14)

# 定义复制文件的函数
function(copy_files_to_destination)

    # 设置源文件路径和目标路径
    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/x64/CMake/DebugWindows")
        set(DESTINATION_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows")

    else ()

        set(SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/x64/CMake/ReleaseWindows")
        set(DESTINATION_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows")

    endif ()

    # 检查源路径是否存在
    if (NOT EXISTS ${SOURCE_PATH})
        message(WARNING "Source path does not exist: ${SOURCE_PATH}")
        return()
    endif ()

    # 检查目标路径是否存在，不存在则创建
    if (NOT EXISTS ${DESTINATION_PATH})
        file(MAKE_DIRECTORY ${DESTINATION_PATH})
    endif ()

    # 复制文件
    file(COPY ${SOURCE_PATH}/ DESTINATION ${DESTINATION_PATH})

endfunction()

copy_files_to_destination()