@echo on
 
set Platform=%1
set Target=%2
set LibPath=%3

xcopy "%LibPath%/ACE/ACE_wrappers/lib/Win32/ACEd.dll" "%Target%" /F /Y
xcopy "%LibPath%/openssl/Win32/Debug/bin/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mysql-connector-c++/BuildWin32/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/Win32/Release-v143/vld_x86.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/Win32/Release-v143/dbghelp.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/Win32/Release-v143/*.manifest" "%Target%" /F /Y
xcopy "%LibPath%/freeglut/BuildWin32/bin/Debug/freeglutd.dll" "%Target%" /F /Y
xcopy "%LibPath%/OpenXLSX/BuildWin32/output/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/protobuf/BuildWin32/bin/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/activemq/activemq-cpp/vs2010-build/Win32/DebugDLL/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/apr/BuildWin32/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/src/mongocxx/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/src/bsoncxx/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/_deps/mongo-c-driver-build/src/libmongoc/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/_deps/mongo-c-driver-build/src/libbson/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/hiredis/BuildWin32/Debug/*.dll" "%Target%" /F /Y