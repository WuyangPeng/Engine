# CMakeList.txt: ThreadingCoreRenderEngineTesting 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.14)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../Code/ThreadingCoreRenderEngineTesting/*.cpp")

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
     add_executable (ThreadingCoreRenderEngineTestingD ${SRC_DIR_LIST})
else()
     add_executable (ThreadingCoreRenderEngineTesting ${SRC_DIR_LIST})
endif()  

# TODO: 如有需要，请添加测试并安装目标。
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")

     if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

          # 执行批处理文件 CopyConfiguration.bat，并传递参数 x64 和 目标路径
          add_custom_target(
                  RunCopyConfigurationBatFile ALL
                  COMMAND
                  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../Bat/CopyConfiguration.bat ${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/ThreadingCoreRenderEngineTesting/ThreadingCoreRenderEngineTesting ThreadingCoreRenderEngineTesting ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows/Configuration
                  COMMENT "Running CopyConfiguration.bat after build"
          )

     else ()

          # 执行批处理文件 CopyConfiguration.bat，并传递参数 x64 和 目标路径
          add_custom_target(
                  RunCopyConfigurationBatFile ALL
                  COMMAND
                  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../Bat/CopyConfiguration.bat ${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/ThreadingCoreRenderEngineTesting/ThreadingCoreRenderEngineTesting ThreadingCoreRenderEngineTesting ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows/Configuration
                  COMMENT "Running CopyConfiguration.bat after build"
          )

     endif ()

     # 检查执行结果
     if (result)
         message(WARNING "Copy Configuration Batch file execution failed with exit code: ${result}")
         message("Error output: ${error}")
     else ()
         message(STATUS "Copy Configuration Batch file executed successfully.")
         message("Output: ${output}")
     endif ()

endif ()
