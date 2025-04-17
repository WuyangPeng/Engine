# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("ThreadingCoreRenderEngineTesting")

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

	include_directories(/data/coding/Libs/boost/)
	include_directories(/data/coding/Libs/GSL/include/)
	include_directories(/data/coding/Libs/STLSoft/include/)
	include_directories(/data/coding/Libs/miniz/)
	include_directories(/data/coding/Libs/miniz/build/)
	include_directories(/data/coding/Libs/pugixml/src/) 
	include_directories(/data/coding/Libs/ACE/ACE_wrappers/)
	include_directories(/data/coding/Libs/protobuf/src/)
	include_directories(/data/coding/Libs/activemq/src/main/)
	include_directories(/data/coding/Libs/mongo-cxx-driver/src/mongocxx/include/mongocxx/v_noabi/)
	include_directories(/data/coding/Libs/mongo-cxx-driver/build/src/mongocxx/lib/)
	include_directories(/data/coding/Libs/mongo-cxx-driver/src/mongocxx/include/)	
	include_directories(/data/coding/Libs/mongo-cxx-driver/src/bsoncxx/include/bsoncxx/v_noabi/)		
	include_directories(/data/coding/Libs/mongo-cxx-driver/build/src/bsoncxx/lib/)
	include_directories(/data/coding/Libs/mongo-cxx-driver/src/bsoncxx/include/)	
	include_directories(/data/coding/Libs/mysql-connector-c++/include/)
	include_directories(/data/coding/Libs/mysql-connector-c++/build/include/mysqlx/) 
	include_directories(/data/coding/Libs/hiredis/) 	
	include_directories(/data/coding/Assist/Code/)
	include_directories(/data/coding/Engine/Code/)	
	include_directories(/data/coding/EngineTesting/Code/)
	include_directories(/data/coding/EngineTesting/EngineWindows)
	include_directories(/data/coding/Assist/AssistWindows)
	
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")

	include_directories($ENV{LibsEnvironmentBaseInclude}/)
	include_directories($ENV{LibsEnvironmentExtendInclude}/)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Code)
	include_directories($ENV{EngineInclude}/)

else()
    # 其他平台下的操作
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

	link_directories(/data/coding/Libs/boost/stage/lib)
	link_directories(/data/coding/Libs/ACE/ACE_wrappers/lib)
	link_directories(/data/coding/Libs/mongo-cxx-driver/build/src/mongocxx)
	link_directories(/data/coding/Libs/mysql-connector-c++/build)
	link_directories(/data/coding/Libs/miniz/build)
	link_directories(/data/coding/Libs/hiredis/build)
	link_directories(/data/coding/Engine/x64/CMake/ReleaseWindows)  	
	link_directories(/data/coding/Assist/x64/CMake/ReleaseWindows)  

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
	
	link_libraries(libExportTest.so)	
	link_libraries(libCSVConfigure.so)
	
	link_libraries(libboost_system.so)	
	link_libraries(libboost_timer.so)	
	link_libraries(libboost_date_time.so)
	link_libraries(libboost_thread.so)
	link_libraries(libACE.so)	
	link_libraries(libmongocxx.so)	
	link_libraries(libmysqlcppconnx.so)
	link_libraries(libactivemq-cpp.so)
	link_libraries(libminiz.a)
	link_libraries(libhiredis.so)
	link_libraries(libGL.so)
	link_libraries(libssl.so)
	link_libraries(libcrypto.so)	

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")

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

else()
    # 其他平台下的操作
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
