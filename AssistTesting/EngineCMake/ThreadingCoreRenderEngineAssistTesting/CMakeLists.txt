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
	include_directories(/data/coding/EngineTesting/Code/Network/NetworkTesting/NetworkMessageSuite/Detail/)
	include_directories(/data/coding/EngineTesting/EngineWindows)
	include_directories(/data/coding/Assist/AssistWindows)	
	include_directories(/data/coding/AssistTesting/Code)	
	
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
	link_directories(/data/coding/Libs/protobuf/build)
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
	link_libraries(libprotobuf.a)	

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	

else()
    # 其他平台下的操作
endif()

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
add_subdirectory ("Editor/AnimationEditor/AnimationEditorTesting")
add_subdirectory ("Editor/AnimationEditor/AnimationEditorAssistTesting")
add_subdirectory ("Editor/DataEditor/DataEditorTesting")
add_subdirectory ("Editor/DataEditor/DataEditorAssistTesting")
add_subdirectory ("Editor/EffectEditor/EffectEditorTesting")
add_subdirectory ("Editor/EffectEditor/EffectEditorAssistTesting")
add_subdirectory ("Editor/FontEditor/FontEditorTesting")
add_subdirectory ("Editor/FontEditor/FontEditorAssistTesting")
add_subdirectory ("Editor/LevelEditor/LevelEditorTesting")
add_subdirectory ("Editor/LevelEditor/LevelEditorAssistTesting")
add_subdirectory ("Editor/MaterialEditor/MaterialEditorTesting")
add_subdirectory ("Editor/MaterialEditor/MaterialEditorAssistTesting")
add_subdirectory ("Editor/ModelEditor/ModelEditorTesting")
add_subdirectory ("Editor/ModelEditor/ModelEditorAssistTesting")
add_subdirectory ("Editor/SceneEditor/SceneEditorTesting")
add_subdirectory ("Editor/SceneEditor/SceneEditorAssistTesting")
add_subdirectory ("Editor/ScriptEditor/ScriptEditorTesting")
add_subdirectory ("Editor/ScriptEditor/ScriptEditorAssistTesting")
add_subdirectory ("Editor/ShaderEditor/ShaderEditorTesting")
add_subdirectory ("Editor/ShaderEditor/ShaderEditorAssistTesting")
add_subdirectory ("Editor/ShadowEditor/ShadowEditorTesting")
add_subdirectory ("Editor/ShadowEditor/ShadowEditorAssistTesting")
add_subdirectory ("Editor/SkeletonEditor/SkeletonEditorTesting")
add_subdirectory ("Editor/SkeletonEditor/SkeletonEditorAssistTesting")
add_subdirectory ("Editor/TerrainEditor/TerrainEditorTesting")
add_subdirectory ("Editor/TerrainEditor/TerrainEditorAssistTesting")
add_subdirectory ("Editor/TextureEditor/TextureEditorTesting")
add_subdirectory ("Editor/TextureEditor/TextureEditorAssistTesting")
add_subdirectory ("Editor/UserInterfaceEditor/UserInterfaceEditorTesting")
add_subdirectory ("Editor/UserInterfaceEditor/UserInterfaceEditorAssistTesting")

add_subdirectory ("Example/ArtificialIntelligenceExample/ArtificialIntelligenceExampleTesting")
add_subdirectory ("Example/AssistToolsExample/AssistToolsExampleTesting")  
add_subdirectory ("Example/CoreToolsExample/CoreToolsExampleTesting")  
add_subdirectory ("Example/DatabaseExample/DatabaseExampleTesting")  
add_subdirectory ("Example/FrameworkExample/FrameworkExampleTesting") 
add_subdirectory ("Example/ImagicsExample/ImagicsExampleTesting")
add_subdirectory ("Example/InputOutputExample/InputOutputExampleTesting")
add_subdirectory ("Example/MathematicsExample/MathematicsExampleTesting")
add_subdirectory ("Example/NetworkExample/NetworkExampleTesting")
add_subdirectory ("Example/PhysicsExample/PhysicsExampleTesting")
add_subdirectory ("Example/RenderingExample/RenderingExampleTesting")
add_subdirectory ("Example/ResourceManagerExample/ResourceManagerExampleTesting")
add_subdirectory ("Example/ScriptExample/ScriptExampleTesting")
add_subdirectory ("Example/SoundEffectExample/SoundEffectExampleTesting") 
add_subdirectory ("Example/SystemExample/SystemExampleTesting") 
add_subdirectory ("Example/UserInterfaceExample/UserInterfaceExampleTesting")

add_subdirectory ("ThreadingCoreRenderEngineAssistTesting")
