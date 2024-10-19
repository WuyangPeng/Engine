@echo on
 
set Platform=%1
set Target=%2

xcopy "%ACEWin32Lib%/ACEd.dll" "%Target%" /F /Y
xcopy "%MysqlConnectorWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorWin32Lib%/vld_x86.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorWin32Lib%/dbghelp.dll" "%Target%" /F /Y
xcopy "%VisualLeakDetectorWin32Lib%/*.manifest" "%Target%" /F /Y
xcopy "%FreeglutWin32DebugBin%/freeglutd.dll" "%Target%" /F /Y
xcopy "%OpenSSLWin32Lib%/../bin/*.dll" "%Target%" /F /Y
xcopy "%OpenXLSXWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%ProtobufWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%ActiveMQWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%AprWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%MongoCxxDriverWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%BsoncxxWin32DebugLib%/*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/mongoc*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/bson*.dll" "%Target%" /F /Y
xcopy "%HiredisWin32DebugLib%/*.dll" "%Target%" /F /Y