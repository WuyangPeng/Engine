# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.8)

project("ThreadingCoreRenderEngine")

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

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

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    include_directories($ENV{LibsEnvironmentBaseInclude}/)
    include_directories($ENV{LibsEnvironmentExtendInclude}/)

else ()
    # 其他平台下的操作
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Code)

if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

    link_directories($ENV{LibsEnvironmentX64DebugLib}/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows)

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/DebugWindows)
	
else ()

    link_directories($ENV{LibsEnvironmentX64ReleaseLib}/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows)

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../x64/CMake/ReleaseWindows)

endif ()

link_directories($ENV{LibsEnvironmentX64Lib}/)

# 包含子项目。
add_subdirectory("System")

add_subdirectory("CoreTools")

add_subdirectory("Network")
add_subdirectory("Database")
add_subdirectory("Script")
add_subdirectory("Mathematics")
add_subdirectory("SoundEffect")
add_subdirectory("InputOutput")

add_subdirectory("ResourceManager")
add_subdirectory("Rendering")
add_subdirectory("Physics")
add_subdirectory("Imagics")

add_subdirectory("Animation")
add_subdirectory("ArtificialIntelligence")
add_subdirectory("UserInterface")

add_subdirectory("AssistTools")

add_subdirectory("Framework")

add_subdirectory("ThreadingCoreRenderEngine")
