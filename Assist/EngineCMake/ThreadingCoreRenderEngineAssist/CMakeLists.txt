# CMakeList.txt: ThreadingCoreRenderEngineAssist 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../Code/ThreadingCoreRenderEngineAssist/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL "Debug")

    set(TARGET_NAME ThreadingCoreRenderEngineAssistD)

else ()

    set(TARGET_NAME ThreadingCoreRenderEngineAssist)

endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    add_executable(${TARGET_NAME} ${SRC_DIR_LIST})

else ()

    add_executable(${TARGET_NAME} WIN32 ${SRC_DIR_LIST})

endif ()

# TODO: 如有需要，请添加测试并安装目标。

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(CONFIGURATION_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows/Configuration)
        set(SHADER_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows/Resource/Shader)

    else ()

        set(CONFIGURATION_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows/Configuration)
        set(SHADER_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows/Resource/Shader)

    endif ()

    set(CONFIGURATION_INPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../AssistWindows/ThreadingCoreRenderEngineAssist/ThreadingCoreRenderEngineAssist/ThreadingCoreRenderEngineAssist)
    set(CONFIGURATION_BAT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../Bat/CopyConfiguration.bat)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        # 执行批处理文件 CopyConfiguration.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyConfigurationBatFileD ALL
                COMMAND
                COMMAND ${CONFIGURATION_BAT_PATH} ${CONFIGURATION_INPUT_PATH} ThreadingCoreRenderEngineAssist ${CONFIGURATION_OUTPUT_PATH}
                COMMENT "Running CopyConfiguration.bat after build"
        )

    else ()

        # 执行批处理文件 CopyConfiguration.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyConfigurationBatFile ALL
                COMMAND
                COMMAND ${CONFIGURATION_BAT_PATH} ${CONFIGURATION_INPUT_PATH} ThreadingCoreRenderEngineAssist ${CONFIGURATION_OUTPUT_PATH}
                COMMENT "Running CopyConfiguration.bat after build"
        )

    endif ()

    # 检查执行结果
    if (result)
        message(WARNING "Copy Configuration Batch file execution failed with exit code: ${result}")
        message("Error output: ${error}")
    else ()
        message(STATUS "Copy Configuration Batch file executed successfully.")
        message("Bat: ${CONFIGURATION_BAT_PATH}")
        message("Input: ${CONFIGURATION_INPUT_PATH}")
        message("Output: ${CONFIGURATION_OUTPUT_PATH}")
    endif ()

    # 创建目录
    if (NOT EXISTS ${SHADER_OUTPUT_PATH})
        file(MAKE_DIRECTORY ${SHADER_OUTPUT_PATH})
        message(STATUS "Created directory: ${SHADER_OUTPUT_PATH}")
    else ()
        message(STATUS "Directory already exists: ${SHADER_OUTPUT_PATH}")
    endif ()

    set(RESOURCE_INPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../AssistWindows/ThreadingCoreRenderEngineAssist/ThreadingCoreRenderEngineAssist/ThreadingCoreRenderEngineAssist)
    set(RESOURCE_BAT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../Bat/CopyResource.bat)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        # 执行批处理文件 CopyResource.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyResourceBatFileD ALL
                COMMAND
                COMMAND ${RESOURCE_BAT_PATH} ${RESOURCE_INPUT_PATH} ${SHADER_OUTPUT_PATH}
                COMMENT "Running CopyResource.bat after build"
        )

    else ()

        # 执行批处理文件 CopyResource.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyResourceBatFile ALL
                COMMAND
                COMMAND ${RESOURCE_BAT_PATH} ${RESOURCE_INPUT_PATH} ${SHADER_OUTPUT_PATH}
                COMMENT "Running CopyResource.bat after build"
        )

    endif ()

    # 检查执行结果
    if (result)
        message(WARNING "Copy Resource Batch file execution failed with exit code: ${result}")
        message("Error output: ${error}")
    else ()
        message(STATUS "Copy Resource Batch file executed successfully.")
        message("Bat: ${RESOURCE_BAT_PATH}")
        message("Input: ${RESOURCE_INPUT_PATH}")
        message("Output: ${SHADER_OUTPUT_PATH}")
    endif ()

endif ()