@echo on
 
start /d %MillenniumHistoryWin32DebugLib% GameClientD.exe
start /d %MillenniumHistoryWin32ReleaseLib% GameClient.exe
start /d %MillenniumHistoryX64DebugLib% GameClientD.exe
start /d %MillenniumHistoryX64ReleaseLib% GameClient.exe
start /d %MillenniumHistoryStaticWin32DebugLib% GameClientStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% GameClientStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% GameClientStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% GameClientStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% GameClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% GameClientStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% GameClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% GameClientStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% GameClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% GameClient.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% GameClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% GameClient.exe

pause