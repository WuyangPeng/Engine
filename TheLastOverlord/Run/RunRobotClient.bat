@echo on
 
start /d %TheLastOverlordWin32DebugLib% RobotClientD.exe
start /d %TheLastOverlordWin32ReleaseLib% RobotClient.exe
start /d %TheLastOverlordX64DebugLib% RobotClientD.exe
start /d %TheLastOverlordX64ReleaseLib% RobotClient.exe
start /d %TheLastOverlordStaticWin32DebugLib% RobotClientStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% RobotClientStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% RobotClientStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% RobotClientStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% RobotClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% RobotClientStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% RobotClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% RobotClientStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% RobotClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% RobotClient.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% RobotClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% RobotClient.exe

pause