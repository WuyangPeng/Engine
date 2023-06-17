# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("ThreadingCoreRenderEngineTesting")

set(CMAKE_CXX_STANDARD 20)

include_directories($ENV{LibsEnvironmentBaseInclude}/)
include_directories($ENV{LibsEnvironmentExtendInclude}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Code)
include_directories($ENV{EngineInclude}/)

if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

    link_directories($ENV{LibsEnvironmentX64DebugLib}/)   
    link_directories($ENV{EngineEngineering}/x64/CMake/DebugWindows/)  
    link_directories($ENV{AssistEngineering}/x64/CMake/DebugWindows/)   
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows) 

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows)

else()

    link_directories($ENV{LibsEnvironmentX64ReleaseLib}/) 
    link_directories($ENV{EngineEngineering}/x64/CMake/ReleaseWindows)  
    link_directories($ENV{AssistEngineering}/x64/CMake/ReleaseWindows/)  
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows) 

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows)

endif()  
 
link_directories($ENV{LibsEnvironmentX64Lib}/)

# 包含子项目。
add_subdirectory ("System/ConsoleSystemTesting")
add_subdirectory ("System/GlutMainLoopTesting")
add_subdirectory ("System/SystemAndroidTesting")
add_subdirectory ("System/SystemOpenGLTesting")
add_subdirectory ("System/SystemTesting")
add_subdirectory ("System/SystemWindowsTesting")

add_subdirectory ("CoreTools/CoreToolsTesting")
add_subdirectory ("CoreTools/ConsoleCoreToolsTesting")

add_subdirectory ("Network/NetworkTesting")
add_subdirectory ("Database/DatabaseTesting")
add_subdirectory ("Script/ScriptTesting")
add_subdirectory ("Mathematics/MathematicsTesting")
add_subdirectory ("SoundEffect/SoundEffectTesting")
add_subdirectory ("InputOutput/InputOutputTesting")

add_subdirectory ("ResourceManager/ResourceManagerTesting")
add_subdirectory ("Rendering/RenderingTesting")
add_subdirectory ("Rendering/RenderingOpenGLTesting")
add_subdirectory ("Rendering/RenderingWindowTesting")
add_subdirectory ("Physics/PhysicsTesting")
add_subdirectory ("Imagics/ImagicsTesting")

add_subdirectory ("Animation/AnimationTesting")
add_subdirectory ("ArtificialIntelligence/ArtificialIntelligenceTesting")
add_subdirectory ("UserInterface/UserInterfaceTesting")

add_subdirectory ("AssistTools/AssistToolsTesting")

add_subdirectory ("Framework/AndroidCallBackUnitTestSuiteTesting")
add_subdirectory ("Framework/AndroidFrameBuildTesting")
add_subdirectory ("Framework/AndroidMessageLoopTesting")
add_subdirectory ("Framework/CameraModelViewControllerTesting")
add_subdirectory ("Framework/DefaultEngineMiddleLayerTesting")
add_subdirectory ("Framework/EngineMiddleLayerTesting")
add_subdirectory ("Framework/FrameworkAndroidTesting")
add_subdirectory ("Framework/FrameworkOpenGLGlutTesting")
add_subdirectory ("Framework/FrameworkTesting")
add_subdirectory ("Framework/FrameworkWindowTesting")
add_subdirectory ("Framework/ModelViewControllerTesting")
add_subdirectory ("Framework/OpenGLGlutCallBackUnitTestSuiteTesting")
add_subdirectory ("Framework/OpenGLGlutFrameBuildTesting")
add_subdirectory ("Framework/PixelModelViewControllerTesting")
add_subdirectory ("Framework/WindowMessageUnitTestSuiteTesting")
add_subdirectory ("Framework/WindowsAPIFrameTesting")

add_subdirectory ("ThreadingCoreRenderEngineTesting")
