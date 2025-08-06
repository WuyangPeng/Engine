@echo on
 
set Platform=%1
set Target=%2
set LibPath=%3

xcopy "%LibPath%/ACE/ACE_wrappers/lib/Win32/ACE.dll" "%Target%" /F /Y
xcopy "%LibPath%/openssl/Win32/Release/bin/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mysql-connector-c++/BuildWin32/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/freeglut/BuildWin32/bin/Release/freeglut.dll" "%Target%" /F /Y
xcopy "%LibPath%/OpenXLSX/BuildWin32/output/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/protobuf/BuildWin32/bin/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/activemq/activemq-cpp/vs2010-build/Win32/ReleaseDLL/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/apr/BuildWin32/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/src/mongocxx/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildWin32/src/bsoncxx/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/hiredis/BuildWin32/Release/*.dll" "%Target%" /F /Y