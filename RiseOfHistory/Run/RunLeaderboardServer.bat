@echo on
 
start /d %RiseOfHistoryWin32DebugLib% LeaderboardServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% LeaderboardServer.exe
start /d %RiseOfHistoryX64DebugLib% LeaderboardServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% LeaderboardServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% LeaderboardServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% LeaderboardServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% LeaderboardServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% LeaderboardServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% LeaderboardServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% LeaderboardServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% LeaderboardServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% LeaderboardServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% LeaderboardServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% LeaderboardServer.exe

pause