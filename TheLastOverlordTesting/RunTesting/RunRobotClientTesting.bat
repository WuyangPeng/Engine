@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% RobotClientTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% RobotClientTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% RobotClientTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% RobotClientTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% RobotClientTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% RobotClientTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% RobotClientTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% RobotClientTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% RobotClientTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% RobotClientTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% RobotClientTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% RobotClientTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% RobotClientTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% RobotClientTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% RobotClientTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% RobotClientTesting.exe

pause