@echo on
 
set Platform=%1
set Target=%2

xcopy "%ACEX64Lib%/ACE.dll" "%Target%" /F /Y
xcopy "%MysqlConnectorX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%FreeglutX64ReleaseBin%/freeglut.dll" "%Target%" /F /Y
xcopy "%OpenSSLX64Lib%/../bin/*.dll" "%Target%" /F /Y
xcopy "%OpenXLSXX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%ProtobufX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%ActiveMQX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%AprX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%MongoCxxDriverX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%BsoncxxX64ReleaseLib%/*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/mongoc*.dll" "%Target%" /F /Y
xcopy "%MongocxxInclude%/../Build%Platform%/mongo-c-driver/bin/bson*.dll" "%Target%" /F /Y
xcopy "%HiredisX64ReleaseLib%/*.dll" "%Target%" /F /Y