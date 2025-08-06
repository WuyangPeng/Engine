@echo on
 
set Platform=%1
set Target=%2
set LibPath=%3

xcopy "%LibPath%/ACE/ACE_wrappers/lib/X64/ACE.dll" "%Target%" /F /Y
xcopy "%LibPath%/openssl/x64/Release/bin/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mysql-connector-c++/BuildX64/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/freeglut/BuildX64/bin/Release/freeglut.dll" "%Target%" /F /Y
xcopy "%LibPath%/OpenXLSX/BuildX64/output/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/protobuf/BuildX64/bin/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/activemq/activemq-cpp/vs2010-build/x64/ReleaseDLL/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/apr/BuildX64/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildX64/src/mongocxx/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildX64/src/bsoncxx/Release/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/hiredis/BuildX64/Release/*.dll" "%Target%" /F /Y