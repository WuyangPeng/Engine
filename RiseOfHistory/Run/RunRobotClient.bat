@echo on
 
start /d %RiseOfHistoryWin32DebugLib% RobotClientD.exe
start /d %RiseOfHistoryWin32ReleaseLib% RobotClient.exe
start /d %RiseOfHistoryX64DebugLib% RobotClientD.exe
start /d %RiseOfHistoryX64ReleaseLib% RobotClient.exe
start /d %RiseOfHistoryStaticWin32DebugLib% RobotClientStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% RobotClientStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% RobotClientStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% RobotClientStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% RobotClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% RobotClientStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% RobotClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% RobotClientStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% RobotClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% RobotClient.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% RobotClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% RobotClient.exe

pause