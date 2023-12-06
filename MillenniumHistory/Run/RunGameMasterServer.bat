@echo on
 
start /d %MillenniumHistoryWin32DebugLib% GameMasterServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% GameMasterServer.exe
start /d %MillenniumHistoryX64DebugLib% GameMasterServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% GameMasterServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% GameMasterServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% GameMasterServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% GameMasterServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% GameMasterServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% GameMasterServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% GameMasterServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% GameMasterServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% GameMasterServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% GameMasterServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% GameMasterServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% GameMasterServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% GameMasterServer.exe

pause