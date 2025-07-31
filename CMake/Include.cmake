set(CMAKE_CXX_STANDARD 20)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    include_directories(/data/coding/External/GSL/include/)
    include_directories(/data/coding/External/boost/)
    include_directories(/data/coding/External/ACE/ACE_wrappers/)
    include_directories(/data/coding/External/mysql-connector-c++/include/)
    include_directories(/data/coding/External/mysql-connector-c++/build/include/mysqlx/)
    include_directories(/data/coding/External/protobuf/src/)
    include_directories(/data/coding/External/protobuf/build/_deps/absl-src/)

    include_directories(/data/coding/Libs/miniz/)
    include_directories(/data/coding/Libs/miniz/build/)
    include_directories(/data/coding/Libs/pugixml/src/)     
    include_directories(/data/coding/Libs/activemq/src/main/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/src/mongocxx/include/mongocxx/v_noabi/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/build/src/mongocxx/lib/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/src/mongocxx/include/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/src/bsoncxx/include/bsoncxx/v_noabi/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/build/src/bsoncxx/lib/)
    include_directories(/data/coding/Libs/mongo-cxx-driver/src/bsoncxx/include/)    
    include_directories(/data/coding/Libs/hiredis/)

    link_directories(/data/coding/External/boost/stage/lib)	
    link_directories(/data/coding/External/ACE/ACE_wrappers/lib)
    link_directories(/data/coding/External/mysql-connector-c++/build)
    link_directories(/data/coding/External/protobuf/build)

    link_directories(/data/coding/Libs/mongo-cxx-driver/build/src/mongocxx)
    link_directories(/data/coding/Libs/mongo-cxx-driver/build/src/bsoncxx)    
    link_directories(/data/coding/Libs/activemq/src/main/.libs)
    link_directories(/data/coding/Libs/miniz/build)
    link_directories(/data/coding/Libs/hiredis/build) 

    link_libraries(libboost_system.so)
    link_libraries(libboost_timer.so)
    link_libraries(libboost_date_time.so)
    link_libraries(libboost_thread.so)
    link_libraries(libboost_charconv.so)
    link_libraries(libACE.so)
    link_libraries(libmongocxx.so)
    link_libraries(libbsoncxx.so)
    link_libraries(libmysqlcppconnx.so)
    link_libraries(libactivemq-cpp.so)
    link_libraries(libminiz.a)
    link_libraries(libhiredis.so)
    link_libraries(libGL.so)
    link_libraries(libssl.so)
    link_libraries(libcrypto.so)
    link_libraries(libprotobuf.a)

elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../External/GSL/include/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../External/KhronosGroup/OpenGL/api/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../External/KhronosGroup/EGL/api/)
	
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/boost/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../ACE/ACE_wrappers/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../mysql/include/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../mysql-connector-c++/include/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../protobuf/src/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../freeglut/include/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../vld/src/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../OpenXLSX/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../pugixml/src/)
	
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/boost/stage/lib/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ACE/ACE_wrappers/lib/x64/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
	
		set(SYSTEM_BUILD_DIRECTORIES "Debug")

    else ()
	
		set(SYSTEM_BUILD_DIRECTORIES "Release")

    endif ()
	
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/mysql/BuildX64/archive_output_directory/${SYSTEM_BUILD_DIRECTORIES}/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/mysql-connector-c++/BuildX64//${SYSTEM_BUILD_DIRECTORIES}/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/protobuf/BuildX64/bin/${SYSTEM_BUILD_DIRECTORIES}/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/freeglut/BuildX64/lib/${SYSTEM_BUILD_DIRECTORIES}/)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/vld/src/bin/x64/${SYSTEM_BUILD_DIRECTORIES}-v143/)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/OpenXLSX/BuildX64/output/${SYSTEM_BUILD_DIRECTORIES}/)

    include_directories($ENV{LibsEnvironmentBaseInclude}/)
    include_directories($ENV{LibsEnvironmentExtendInclude}/)

    if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
       
        link_directories($ENV{LibsEnvironmentX64DebugLib}/) 

    else ()

        link_directories($ENV{LibsEnvironmentX64ReleaseLib}/) 

    endif ()

    link_directories($ENV{LibsEnvironmentX64Lib}/)

else ()

    # 其他平台下的操作

endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Code)

if (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))

    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows)

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/DebugWindows)

else ()

    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/ReleaseWindows)

    set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../x64/CMake/ReleaseWindows)

endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")

    # 编译选项（编译器）
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}   -fPIC")

    # 符号可见性
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}   -fvisibility=hidden")

    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")

endif ()