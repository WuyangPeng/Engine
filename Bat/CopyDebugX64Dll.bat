@echo on
 
set Platform=%1
set Target=%2
set LibPath=%3

xcopy "%LibPath%/ACE/ACE_wrappers/lib/X64/ACEd.dll" "%Target%" /F /Y
xcopy "%LibPath%/openssl/x64/Debug/bin/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mysql-connector-c++/BuildX64/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/x64/Debug-v143/vld_x86.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/x64/Debug-v143/dbghelp.dll" "%Target%" /F /Y
xcopy "%LibPath%/vld/src/bin/x64/Debug-v143/*.manifest" "%Target%" /F /Y
xcopy "%LibPath%/freeglut/BuildX64/bin/Debug/freeglutd.dll" "%Target%" /F /Y
xcopy "%LibPath%/OpenXLSX/BuildX64/output/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/protobuf/BuildX64/bin/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/activemq/activemq-cpp/vs2010-build/x64/DebugDLL/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/apr/BuildX64/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildX64/src/mongocxx/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/mongo-cxx-driver/BuildX64/src/bsoncxx/Debug/*.dll" "%Target%" /F /Y
xcopy "%LibPath%/hiredis/BuildX64/Debug/*.dll" "%Target%" /F /Y