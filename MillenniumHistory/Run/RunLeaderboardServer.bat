@echo on
 
start /d %MillenniumHistoryWin32DebugLib% LeaderboardServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% LeaderboardServer.exe
start /d %MillenniumHistoryX64DebugLib% LeaderboardServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% LeaderboardServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% LeaderboardServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% LeaderboardServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% LeaderboardServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% LeaderboardServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% LeaderboardServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% LeaderboardServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% LeaderboardServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% LeaderboardServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% LeaderboardServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% LeaderboardServer.exe

pause