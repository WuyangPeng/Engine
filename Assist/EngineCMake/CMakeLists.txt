# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.14)

project("ThreadingCoreRenderEngine")

# 引入路径配置文件
include(../../CMake/Include.cmake)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    include_directories(/data/coding/Assist/Code/)
    include_directories(/data/coding/Engine/Code/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        link_directories(/data/coding/Engine/x64/CMake/DebugWindows)

        link_libraries(libSystemD.so)
        link_libraries(libCoreToolsD.so)
        link_libraries(libNetworkD.so)
        link_libraries(libDatabaseD.so)
        link_libraries(libScriptD.so)
        link_libraries(libMathematicsD.so)
        link_libraries(libSoundEffectD.so)
        link_libraries(libInputOutputD.so)
        link_libraries(libResourceManagerD.so)
        link_libraries(libRenderingD.so)
        link_libraries(libPhysicsD.so)
        link_libraries(libImagicsD.so)
        link_libraries(libAnimationD.so)
        link_libraries(libArtificialIntelligenceD.so)
        link_libraries(libUserInterfaceD.so)
        link_libraries(libAssistToolsD.so)
        link_libraries(libFrameworkD.so)

    else ()

        link_directories(/data/coding/Engine/x64/CMake/ReleaseWindows)

        link_libraries(libSystem.so)
        link_libraries(libCoreTools.so)
        link_libraries(libNetwork.so)
        link_libraries(libDatabase.so)
        link_libraries(libScript.so)
        link_libraries(libMathematics.so)
        link_libraries(libSoundEffect.so)
        link_libraries(libInputOutput.so)
        link_libraries(libResourceManager.so)
        link_libraries(libRendering.so)
        link_libraries(libPhysics.so)
        link_libraries(libImagics.so)
        link_libraries(libAnimation.so)
        link_libraries(libArtificialIntelligence.so)
        link_libraries(libUserInterface.so)
        link_libraries(libAssistTools.so)
        link_libraries(libFramework.so)

    endif ()

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/Code/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(BAT_NAME CopyDebugX64Dll)
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/x64/CMake/DebugWindows/)

    else ()

        set(BAT_NAME CopyReleaseX64Dll)
        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/x64/CMake/ReleaseWindows)

    endif ()

    # 创建目录
    if (NOT EXISTS ${EXECUTABLE_OUTPUT_PATH})
        file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
        message(STATUS "Created directory: ${EXECUTABLE_OUTPUT_PATH}")
    else ()
        message(STATUS "Directory already exists: ${EXECUTABLE_OUTPUT_PATH}")
    endif ()

    # 执行批处理文件 CopyX64Dll.bat，并传递参数 x64 和 目标路径
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

endif ()

# 包含子项目。

add_subdirectory("Editor/Editor/Editor")
add_subdirectory("Editor/AnimationEditor/AnimationEditor")
add_subdirectory("Editor/AnimationEditor/AnimationEditorAssist")
add_subdirectory("Editor/DataEditor/DataEditor")
add_subdirectory("Editor/DataEditor/DataEditorAssist")
add_subdirectory("Editor/EffectEditor/EffectEditor")
add_subdirectory("Editor/EffectEditor/EffectEditorAssist")
add_subdirectory("Editor/FontEditor/FontEditor")
add_subdirectory("Editor/FontEditor/FontEditorAssist")
add_subdirectory("Editor/LevelEditor/LevelEditor")
add_subdirectory("Editor/LevelEditor/LevelEditorAssist")
add_subdirectory("Editor/MaterialEditor/MaterialEditor")
add_subdirectory("Editor/MaterialEditor/MaterialEditorAssist")
add_subdirectory("Editor/ModelEditor/ModelEditor")
add_subdirectory("Editor/ModelEditor/ModelEditorAssist")
add_subdirectory("Editor/SceneEditor/SceneEditor")
add_subdirectory("Editor/SceneEditor/SceneEditorAssist")
add_subdirectory("Editor/ScriptEditor/ScriptEditor")
add_subdirectory("Editor/ScriptEditor/ScriptEditorAssist")
add_subdirectory("Editor/ShaderEditor/ShaderEditor")
add_subdirectory("Editor/ShaderEditor/ShaderEditorAssist")
add_subdirectory("Editor/ShadowEditor/ShadowEditor")
add_subdirectory("Editor/ShadowEditor/ShadowEditorAssist")
add_subdirectory("Editor/SkeletonEditor/SkeletonEditor")
add_subdirectory("Editor/SkeletonEditor/SkeletonEditorAssist")
add_subdirectory("Editor/TerrainEditor/TerrainEditor")
add_subdirectory("Editor/TerrainEditor/TerrainEditorAssist")
add_subdirectory("Editor/TextureEditor/TextureEditor")
add_subdirectory("Editor/TextureEditor/TextureEditorAssist")
add_subdirectory("Editor/UserInterfaceEditor/UserInterfaceEditor")
add_subdirectory("Editor/UserInterfaceEditor/UserInterfaceEditorAssist")

add_subdirectory("Toolset/Animation/AnimationToolset")
add_subdirectory("Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset")
add_subdirectory("Toolset/AssistTools/AssistToolsToolset")
add_subdirectory("Toolset/AssistTools/GameTemplate")
add_subdirectory("Toolset/AssistTools/GameTestingTemplate")
add_subdirectory("Toolset/CoreTools/BatchConversion")
add_subdirectory("Toolset/CoreTools/CMainFunctionHelper")
add_subdirectory("Toolset/CoreTools/CoreToolsToolset")
add_subdirectory("Toolset/CoreTools/CSVConfigure")
add_subdirectory("Toolset/CoreTools/DllMainFunction")
add_subdirectory("Toolset/CoreTools/ExportTest")
add_subdirectory("Toolset/CoreTools/JsonConfigure")
add_subdirectory("Toolset/CoreTools/MainFunction")
add_subdirectory("Toolset/Database/DatabaseEntity")
add_subdirectory("Toolset/Database/DatabaseToolset")
add_subdirectory("Toolset/Editor/EditorToolset")
add_subdirectory("Toolset/Example/ExampleToolset")
add_subdirectory("Toolset/Framework/AndroidMainEntryPoint1")
add_subdirectory("Toolset/Framework/AndroidMainEntryPoint2")
add_subdirectory("Toolset/Framework/AndroidMainFunctionHelper1")
add_subdirectory("Toolset/Framework/ConsoleMainFunctionHelper1")
add_subdirectory("Toolset/Framework/ConsoleMainFunctionHelperBase1")
add_subdirectory("Toolset/Framework/FrameworkToolset")
add_subdirectory("Toolset/Framework/GlutMainEntryPoint1")
add_subdirectory("Toolset/Framework/GlutMainEntryPoint2")
add_subdirectory("Toolset/Framework/MacintoshMainFunctionHelper1")
add_subdirectory("Toolset/Framework/MainEntryPoint1")
add_subdirectory("Toolset/Framework/MainEntryPoint2")
add_subdirectory("Toolset/Framework/MainFunctionHelperBase1")
add_subdirectory("Toolset/Framework/OpenGLGlutMainFunctionHelper1")
add_subdirectory("Toolset/Framework/WindowMainFunctionHelper1")
add_subdirectory("Toolset/Framework/WindowMessageLoop1")
add_subdirectory("Toolset/Framework/WinMainEntryPoint1")
add_subdirectory("Toolset/Framework/WinMainEntryPoint2")
add_subdirectory("Toolset/Framework/WinMainEntryPoint3")
add_subdirectory("Toolset/Framework/WinMainEntryPoint4")
add_subdirectory("Toolset/Imagics/ImagicsToolset")
add_subdirectory("Toolset/InputOutput/InputOutputToolset")
add_subdirectory("Toolset/Mathematics/MathematicsToolset")
add_subdirectory("Toolset/Network/NetworkToolset")
add_subdirectory("Toolset/Physics/PhysicsToolset")
add_subdirectory("Toolset/Rendering/RenderingToolset")
add_subdirectory("Toolset/ResourceManager/ResourceManagerToolset")
add_subdirectory("Toolset/Script/ScriptToolset")
add_subdirectory("Toolset/SoundEffect/SoundEffectToolset")
add_subdirectory("Toolset/System/ProcessTest")
add_subdirectory("Toolset/System/ResourcesLibrary")
add_subdirectory("Toolset/System/SystemToolset")
add_subdirectory("Toolset/System/TcpClient")
add_subdirectory("Toolset/System/UdpClient")
add_subdirectory("Toolset/Toolset/Toolset")
add_subdirectory("Toolset/UserInterface/UserInterfaceToolset")

add_subdirectory("Example/Example/Example")
add_subdirectory("Example/ArtificialIntelligenceExample/ArtificialIntelligenceExample")
add_subdirectory("Example/AssistToolsExample/AssistToolsExample")
add_subdirectory("Example/CoreToolsExample/CoreToolsExample")
add_subdirectory("Example/DatabaseExample/DatabaseExample")
add_subdirectory("Example/FrameworkExample/FrameworkExample")
add_subdirectory("Example/ImagicsExample/ImagicsExample")
add_subdirectory("Example/InputOutputExample/InputOutputExample")
add_subdirectory("Example/MathematicsExample/MathematicsExample")
add_subdirectory("Example/NetworkExample/NetworkExample")
add_subdirectory("Example/PhysicsExample/PhysicsExample")
add_subdirectory("Example/RenderingExample/RenderingExample")
add_subdirectory("Example/ResourceManagerExample/ResourceManagerExample")
add_subdirectory("Example/ScriptExample/ScriptExample")
add_subdirectory("Example/SoundEffectExample/SoundEffectExample")
add_subdirectory("Example/SystemExample/SystemExample")
add_subdirectory("Example/UserInterfaceExample/UserInterfaceExample")

add_subdirectory("ThreadingCoreRenderEngineAssist")
