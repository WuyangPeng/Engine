@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% RobotClientCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% RobotClientCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% RobotClientCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% RobotClientCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% RobotClientCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% RobotClientCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% RobotClientCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% RobotClientCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% RobotClientCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% RobotClientCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% RobotClientCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% RobotClientCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% RobotClientCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% RobotClientCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% RobotClientCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% RobotClientCoreTesting.exe

pause