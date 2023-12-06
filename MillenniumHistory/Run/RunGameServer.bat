@echo on
 
start /d %MillenniumHistoryWin32DebugLib% GameServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% GameServer.exe
start /d %MillenniumHistoryX64DebugLib% GameServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% GameServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% GameServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% GameServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% GameServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% GameServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% GameServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% GameServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% GameServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% GameServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% GameServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% GameServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% GameServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% GameServer.exe

pause