@echo on
 
start /d %MillenniumHistoryWin32DebugLib% RobotClientD.exe
start /d %MillenniumHistoryWin32ReleaseLib% RobotClient.exe
start /d %MillenniumHistoryX64DebugLib% RobotClientD.exe
start /d %MillenniumHistoryX64ReleaseLib% RobotClient.exe
start /d %MillenniumHistoryStaticWin32DebugLib% RobotClientStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% RobotClientStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% RobotClientStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% RobotClientStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% RobotClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% RobotClientStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% RobotClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% RobotClientStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% RobotClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% RobotClient.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% RobotClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% RobotClient.exe

pause