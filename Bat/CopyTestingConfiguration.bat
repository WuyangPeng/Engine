@echo on
 
set ProjectDir=%1
set ProjectName=%2
set Target=%3

xcopy "%ProjectDir%/Configuration/%ProjectName%.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/ProjectTesting.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/ProjectTesting.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/EnvironmentVariable.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/EngineDirectory.json" "%Target%" /F /Y