@echo on
 
set Platform=%1
set Target=%2

xcopy "%ACEWin32Lib%/ACE.dll" "%Target%" /F /Y
xcopy "%MysqlConnectorWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%FreeglutWin32ReleaseBin%/freeglut.dll" "%Target%" /F /Y
xcopy "%OpenSSLWin32Lib%/../bin/*.dll" "%Target%" /F /Y
xcopy "%OpenXLSXWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%ProtobufWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%ActiveMQWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%AprWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%MongoCxxDriverWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%BsoncxxWin32ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/mongoc*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/bson*.dll" "%Target%" /F /Y
xcopy "%HiredisWin32ReleaseLib%/*.dll" "%Target%" /F /Y