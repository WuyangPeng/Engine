@echo on
 
set ProjectDir=%1
set ProjectName=%2
set Target=%3

xcopy "%ProjectDir%/Configuration/EnvironmentVariable.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/EngineDirectory.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/%ProjectName%/Renderer.json" "%Target%/%ProjectName%/" /F /Y
xcopy "%ProjectDir%/Configuration/Project.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/Testing.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/%ProjectName%.json" %Target%" /F /Y
xcopy "%ProjectDir%/Configuration/Global.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/Smtp.json" "%Target%" /F /Y
xcopy "%ProjectDir%/Configuration/Database.json" "%Target%" /F /Y