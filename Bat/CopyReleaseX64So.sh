@echo on
 
xcopy "/data/coding/Libs/ACE/ACE_wrappers/lib/libACE.so" "/data/coding/EngineTesting/x64/CMake/ReleaseWindows/" /F /Y
xcopy "/data/coding/Libs/mysql-connector-c++/build/*.so" "/data/coding/EngineTesting/x64/CMake/ReleaseWindows/" /F /Y
xcopy "/data/coding/Libs/activemq/src/main/.libs/*.so" "/data/coding/EngineTesting/x64/CMake/ReleaseWindows/" /F /Y