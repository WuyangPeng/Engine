# CMakeList.txt: ThreadingCoreRenderEngineTesting 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../Code/ThreadingCoreRenderEngineTesting/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_executable(ThreadingCoreRenderEngineTestingD ${SRC_DIR_LIST})
else ()
    add_executable(ThreadingCoreRenderEngineTesting ${SRC_DIR_LIST})
endif ()

# TODO: 如有需要，请添加测试并安装目标。

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(CONFIGURATION_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows/Configuration)

    else ()

        set(CONFIGURATION_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows/Configuration)

    endif ()

    set(CONFIGURATION_INPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/ThreadingCoreRenderEngineTesting/ThreadingCoreRenderEngineTesting)
    set(BAT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../Bat/CopyTestingConfiguration.bat)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        # 执行批处理文件 CopyTestingConfiguration.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyConfigurationBatFileD ALL
                COMMAND
                COMMAND ${BAT_PATH} ${CONFIGURATION_INPUT_PATH} ThreadingCoreRenderEngineTesting ${CONFIGURATION_OUTPUT_PATH}
                COMMENT "Running CopyConfiguration.bat after build"
        )

    else ()

        # 执行批处理文件 CopyTestingConfiguration.bat，并传递参数 x64 和 目标路径
        add_custom_target(
                RunCopyConfigurationBatFile ALL
                COMMAND
                COMMAND ${BAT_PATH} ${CONFIGURATION_INPUT_PATH} ThreadingCoreRenderEngineTesting ${CONFIGURATION_OUTPUT_PATH}
                COMMENT "Running CopyConfiguration.bat after build"
        )

    endif ()

    # 检查执行结果
    if (result)
        message(WARNING "Copy Configuration Batch file execution failed with exit code: ${result}")
        message("Error output: ${error}")
    else ()
        message(STATUS "Copy Configuration Batch file executed successfully.")
        message("Bat: ${BAT_PATH}")
        message("Input: ${CONFIGURATION_INPUT_PATH}")
        message("Output: ${CONFIGURATION_OUTPUT_PATH}")
    endif ()

endif ()