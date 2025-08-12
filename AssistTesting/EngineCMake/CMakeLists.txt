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
    include_directories(/data/coding/AssistTesting/Code/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(BAT_NAME CopyDebugX64Dll)
        link_directories(/data/coding/Assist/x64/CMake/DebugWindows)

    else ()

        set(BAT_NAME CopyReleaseX64Dll)
        link_directories(/data/coding/Assist/x64/CMake/ReleaseWindows)

    endif ()

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../EngineTesting/Code/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Assist/Code/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../AssistTesting/Code/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(BAT_NAME CopyDebugX64Dll)
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows)

        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Assist/x64/CMake/DebugWindows)

    else ()

        set(BAT_NAME CopyReleaseX64Dll)
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/ReleaseWindows)

        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Assist/x64/CMake/ReleaseWindows)

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
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../Bat/${BAT_NAME}.bat x64 ${EXECUTABLE_OUTPUT_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/
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
add_subdirectory("Editor/AnimationEditor/AnimationEditorTesting")
add_subdirectory("Editor/AnimationEditor/AnimationEditorAssistTesting")
add_subdirectory("Editor/DataEditor/DataEditorTesting")
add_subdirectory("Editor/DataEditor/DataEditorAssistTesting")
add_subdirectory("Editor/EffectEditor/EffectEditorTesting")
add_subdirectory("Editor/EffectEditor/EffectEditorAssistTesting")
add_subdirectory("Editor/FontEditor/FontEditorTesting")
add_subdirectory("Editor/FontEditor/FontEditorAssistTesting")
add_subdirectory("Editor/LevelEditor/LevelEditorTesting")
add_subdirectory("Editor/LevelEditor/LevelEditorAssistTesting")
add_subdirectory("Editor/MaterialEditor/MaterialEditorTesting")
add_subdirectory("Editor/MaterialEditor/MaterialEditorAssistTesting")
add_subdirectory("Editor/ModelEditor/ModelEditorTesting")
add_subdirectory("Editor/ModelEditor/ModelEditorAssistTesting")
add_subdirectory("Editor/SceneEditor/SceneEditorTesting")
add_subdirectory("Editor/SceneEditor/SceneEditorAssistTesting")
add_subdirectory("Editor/ScriptEditor/ScriptEditorTesting")
add_subdirectory("Editor/ScriptEditor/ScriptEditorAssistTesting")
add_subdirectory("Editor/ShaderEditor/ShaderEditorTesting")
add_subdirectory("Editor/ShaderEditor/ShaderEditorAssistTesting")
add_subdirectory("Editor/ShadowEditor/ShadowEditorTesting")
add_subdirectory("Editor/ShadowEditor/ShadowEditorAssistTesting")
add_subdirectory("Editor/SkeletonEditor/SkeletonEditorTesting")
add_subdirectory("Editor/SkeletonEditor/SkeletonEditorAssistTesting")
add_subdirectory("Editor/TerrainEditor/TerrainEditorTesting")
add_subdirectory("Editor/TerrainEditor/TerrainEditorAssistTesting")
add_subdirectory("Editor/TextureEditor/TextureEditorTesting")
add_subdirectory("Editor/TextureEditor/TextureEditorAssistTesting")
add_subdirectory("Editor/UserInterfaceEditor/UserInterfaceEditorTesting")
add_subdirectory("Editor/UserInterfaceEditor/UserInterfaceEditorAssistTesting")

add_subdirectory("Example/AnimationExample/AnimationExampleTesting")
add_subdirectory("Example/ArtificialIntelligenceExample/ArtificialIntelligenceExampleTesting")
add_subdirectory("Example/AssistToolsExample/AssistToolsExampleTesting")
add_subdirectory("Example/CoreToolsExample/CoreToolsExampleTesting")
add_subdirectory("Example/DatabaseExample/DatabaseExampleTesting")
add_subdirectory("Example/FrameworkExample/FrameworkExampleTesting")
add_subdirectory("Example/ImagicsExample/ImagicsExampleTesting")
add_subdirectory("Example/InputOutputExample/InputOutputExampleTesting")
add_subdirectory("Example/MathematicsExample/MathematicsExampleTesting")
add_subdirectory("Example/NetworkExample/NetworkExampleTesting")
add_subdirectory("Example/PhysicsExample/PhysicsExampleTesting")
add_subdirectory("Example/RenderingExample/RenderingExampleTesting")
add_subdirectory("Example/ResourceManagerExample/ResourceManagerExampleTesting")
add_subdirectory("Example/ScriptExample/ScriptExampleTesting")
add_subdirectory("Example/SoundEffectExample/SoundEffectExampleTesting")
add_subdirectory("Example/SystemExample/SystemExampleTesting")
add_subdirectory("Example/UserInterfaceExample/UserInterfaceExampleTesting")

add_subdirectory("ThreadingCoreRenderEngineAssistTesting")