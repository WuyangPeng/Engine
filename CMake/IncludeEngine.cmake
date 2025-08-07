set(CMAKE_CXX_STANDARD 20)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

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

        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/x64/CMake/DebugWindows/)

    else ()

        link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/x64/CMake/ReleaseWindows)

    endif ()

endif ()