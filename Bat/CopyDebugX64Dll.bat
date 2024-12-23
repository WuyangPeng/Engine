@echo on
 
set Platform=%1
set Target=%2

xcopy "%ACEX64Lib%/ACEd.dll" "%Target%" /F /Y
xcopy "%MysqlConnectorX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorX64Lib%/vld_x64.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorX64Lib%/dbghelp.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorX64Lib%/*.manifest" "%Target%" /F /Y
xcopy "%FreeglutX64DebugBin%/freeglutd.dll" "%Target%" /F /Y
xcopy "%OpenSSLX64Lib%/../bin/*.dll" "%Target%" /F /Y
xcopy "%OpenXLSXX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%ProtobufX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%ActiveMQX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%AprX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%MongoCxxDriverX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%BsoncxxX64DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/mongoc*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/bson*.dll" "%Target%" /F /Y
xcopy "%HiredisX64DebugLib%/*.dll" "%Target%" /F /Y