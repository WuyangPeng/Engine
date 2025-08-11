# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.14)

project("ThreadingCoreRenderEngineTesting")

# 引入路径配置文件
include(../../CMake/Include.cmake)
include(../../CMake/IncludeEngine.cmake)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    include_directories(/data/coding/EngineTesting/Code/)
    include_directories(/data/coding/Assist/Code/)
    include_directories(/data/coding/EngineTesting/EngineWindows/)
    include_directories(/data/coding/Assist/AssistWindows/)
    include_directories(/data/coding/EngineTesting/Code/Network/NetworkTesting/NetworkMessageSuite/Detail/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(BAT_NAME CopyDebugX64Dll)
        link_directories(/data/coding/Assist/x64/CMake/DebugWindows)

        link_libraries(libExportTestD.so)
        link_libraries(libCSVConfigureD.so)

    else ()

        set(BAT_NAME CopyReleaseX64Dll)
        link_directories(/data/coding/Assist/x64/CMake/ReleaseWindows)

        link_libraries(libExportTest.so)
        link_libraries(libCSVConfigure.so)

    endif ()

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(BAT_NAME CopyDebugX64Dll)
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows)

    else ()

        set(BAT_NAME CopyReleaseX64Dll)
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/ReleaseWindows)

    endif ()

    # 创建目录
    if (NOT EXISTS ${EXECUTABLE_OUTPUT_PATH})
        file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
        message(STATUS "Created directory: ${EXECUTABLE_OUTPUT_PATH}")
    else ()
        message(STATUS "Directory already exists: ${EXECUTABLE_OUTPUT_PATH}")
    endif ()

    # 执行批处理文件 CopyDebugX64Dll.bat，并传递参数 x64 和 目标路径
    add_custom_target(
            RunBatFile ALL
            COMMAND
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../Bat/${BAT_NAME}.bat x64 ${EXECUTABLE_OUTPUT_PATH}
            COMMENT "Running ${BAT_NAME}.bat after build"
    )

    # 检查执行结果
    if (result)
        message(WARNING "Batch file execution failed with exit code: ${result}")
        message("Error output: ${error}")
    else ()
        message(STATUS "Batch file executed successfully.")
        message("Output: ${EXECUTABLE_OUTPUT_PATH}")
    endif ()

    add_custom_target(copy_files ALL
            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -P ${CMAKE_CURRENT_SOURCE_DIR}/CopyFiles.cmake
            COMMENT "Copying files to destination before build"
    )

    add_custom_target(copy_testing_files ALL
            COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -P ${CMAKE_CURRENT_SOURCE_DIR}/CopyTestingFiles.cmake
            COMMENT "Copying Testing files to destination before build"
    )

else ()

    # 其他平台下的操作

endif ()

# 包含子项目。
add_subdirectory("System/ConsoleSystemTesting")
add_subdirectory("System/GlutMainLoopTesting")
add_subdirectory("System/SystemAndroidTesting")
add_subdirectory("System/SystemOpenGLTesting")
add_subdirectory("System/SystemTesting")
add_subdirectory("System/SystemWindowsTesting")

add_subdirectory("CoreTools/CoreToolsTesting")
add_subdirectory("CoreTools/ConsoleCoreToolsTesting")

add_subdirectory("Network/NetworkTesting")
add_subdirectory("Database/DatabaseTesting")
add_subdirectory("Script/ScriptTesting")
add_subdirectory("Mathematics/MathematicsTesting")
add_subdirectory("SoundEffect/SoundEffectTesting")
add_subdirectory("InputOutput/InputOutputTesting")

add_subdirectory("ResourceManager/ResourceManagerTesting")
add_subdirectory("Rendering/RenderingTesting")
add_subdirectory("Rendering/RenderingOpenGLTesting")
add_subdirectory("Rendering/RenderingWindowTesting")
add_subdirectory("Physics/PhysicsTesting")
add_subdirectory("Imagics/ImagicsTesting")

add_subdirectory("Animation/AnimationTesting")
add_subdirectory("ArtificialIntelligence/ArtificialIntelligenceTesting")
add_subdirectory("UserInterface/UserInterfaceTesting")

add_subdirectory("AssistTools/AssistToolsTesting")

add_subdirectory("Framework/AndroidCallBackUnitTestSuiteTesting")
add_subdirectory("Framework/AndroidFrameBuildTesting")
add_subdirectory("Framework/AndroidMessageLoopTesting")
add_subdirectory("Framework/CameraModelViewControllerTesting")
add_subdirectory("Framework/DefaultEngineMiddleLayerTesting")
add_subdirectory("Framework/EngineMiddleLayerTesting")
add_subdirectory("Framework/FrameworkAndroidTesting")
add_subdirectory("Framework/FrameworkOpenGLGlutTesting")
add_subdirectory("Framework/FrameworkTesting")
add_subdirectory("Framework/FrameworkWindowTesting")
add_subdirectory("Framework/ModelViewControllerTesting")
add_subdirectory("Framework/OpenGLGlutCallBackUnitTestSuiteTesting")
add_subdirectory("Framework/OpenGLGlutFrameBuildTesting")
add_subdirectory("Framework/PixelModelViewControllerTesting")
add_subdirectory("Framework/WindowMessageUnitTestSuiteTesting")
add_subdirectory("Framework/WindowsAPIFrameTesting")

add_subdirectory("ThreadingCoreRenderEngineTesting")