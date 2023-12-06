@echo on
 
start /d %MillenniumHistoryWin32DebugLib% FightingServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% FightingServer.exe
start /d %MillenniumHistoryX64DebugLib% FightingServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% FightingServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% FightingServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% FightingServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% FightingServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% FightingServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% FightingServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% FightingServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% FightingServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% FightingServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% FightingServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% FightingServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% FightingServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% FightingServer.exe

pause