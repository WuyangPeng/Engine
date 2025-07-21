# CopyFiles.cmake
cmake_minimum_required(VERSION 3.14)

function(copy_testing_files_to_destination SOURCE_PATH)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        set(DESTINATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows/Configuration)

    else ()

        set(DESTINATION_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows/Configuration)

    endif ()

    message("CopyFrom: ${SOURCE_PATH}")
    message("CopyTo: ${DESTINATION_PATH}")
    file(COPY ${SOURCE_PATH} DESTINATION ${DESTINATION_PATH})

endfunction()

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/ConsoleSystemTesting/Configuration/ConsoleSystemTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/GlutMainLoopTesting/Configuration/GlutMainLoopTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/SystemAndroidTesting/Configuration/SystemAndroidTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/SystemOpenGLTesting/Configuration/SystemOpenGLTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/SystemTesting/Configuration/SystemTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/System/SystemWindowsTesting/Configuration/SystemWindowsTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/CoreTools/CoreToolsTesting/Configuration/CoreToolsTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/CoreTools/ConsoleCoreToolsTesting/Configuration/ConsoleCoreToolsTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Network/NetworkTesting/Configuration/NetworkTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Database/DatabaseTesting/Configuration/DatabaseTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Script/ScriptTesting/Configuration/ScriptTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Mathematics/MathematicsTesting/Configuration/MathematicsTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/SoundEffect/SoundEffectTesting/Configuration/SoundEffectTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/InputOutput/InputOutputTesting/Configuration/InputOutputTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/ResourceManager/ResourceManagerTesting/Configuration/ResourceManagerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Rendering/RenderingTesting/Configuration/RenderingTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Rendering/RenderingOpenGLTesting/Configuration/RenderingOpenGLTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Rendering/RenderingWindowTesting/Configuration/RenderingWindowTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Physics/PhysicsTesting/Configuration/PhysicsTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Imagics/ImagicsTesting/Configuration/ImagicsTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Animation/AnimationTesting/Configuration/AnimationTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/ArtificialIntelligence/ArtificialIntelligenceTesting/Configuration/ArtificialIntelligenceTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/UserInterface/UserInterfaceTesting/Configuration/UserInterfaceTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/AssistTools/AssistToolsTesting/Configuration/AssistToolsTesting.json")

copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/AndroidCallBackUnitTestSuiteTesting/Configuration/AndroidCallBackUnitTestSuiteTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/AndroidFrameBuildTesting/Configuration/AndroidFrameBuildTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/AndroidMessageLoopTesting/Configuration/AndroidMessageLoopTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/CameraModelViewControllerTesting/Configuration/CameraModelViewControllerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/DefaultEngineMiddleLayerTesting/Configuration/DefaultEngineMiddleLayerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/EngineMiddleLayerTesting/Configuration/EngineMiddleLayerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/FrameworkAndroidTesting/Configuration/FrameworkAndroidTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/FrameworkOpenGLGlutTesting/Configuration/FrameworkOpenGLGlutTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/FrameworkTesting/Configuration/FrameworkTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/FrameworkWindowTesting/Configuration/FrameworkWindowTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/ModelViewControllerTesting/Configuration/ModelViewControllerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/OpenGLGlutCallBackUnitTestSuiteTesting/Configuration/OpenGLGlutCallBackUnitTestSuiteTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/OpenGLGlutFrameBuildTesting/Configuration/OpenGLGlutFrameBuildTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/PixelModelViewControllerTesting/Configuration/PixelModelViewControllerTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/WindowMessageUnitTestSuiteTesting/Configuration/WindowMessageUnitTestSuiteTesting.json")
copy_testing_files_to_destination("${CMAKE_CURRENT_SOURCE_DIR}/../../EngineWindows/Framework/WindowsAPIFrameTesting/Configuration/WindowsAPIFrameTesting.json")
