# CMakeList.txt: Imagics 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE SRC_DIR_LIST "${CMAKE_SOURCE_DIR}/../Code/Imagics/*.cpp")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

        link_libraries(libSystemD.so)
        link_libraries(libCoreToolsD.so)
        link_libraries(libNetworkD.so)
        link_libraries(libDatabaseD.so)
        link_libraries(libScriptD.so)
        link_libraries(libMathematicsD.so)
        link_libraries(libSoundEffectD.so)
        link_libraries(libInputOutputD.so)

    else ()

        link_libraries(libSystem.so)
        link_libraries(libCoreTools.so)
        link_libraries(libNetwork.so)
        link_libraries(libDatabase.so)
        link_libraries(libScript.so)
        link_libraries(libMathematics.so)
        link_libraries(libSoundEffect.so)
        link_libraries(libInputOutput.so)

    endif ()

endif ()

# 将源代码添加到此项目的可执行文件。
if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_library(ImagicsD SHARED ${SRC_DIR_LIST})
else ()
    add_library(Imagics SHARED ${SRC_DIR_LIST})
endif ()

# TODO: 如有需要，请添加测试并安装目标。
