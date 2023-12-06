@echo on
 
start /d %MillenniumHistoryWin32DebugLib% MessageClientD.exe
start /d %MillenniumHistoryWin32ReleaseLib% MessageClient.exe
start /d %MillenniumHistoryX64DebugLib% MessageClientD.exe
start /d %MillenniumHistoryX64ReleaseLib% MessageClient.exe
start /d %MillenniumHistoryStaticWin32DebugLib% MessageClientStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% MessageClientStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% MessageClientStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% MessageClientStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% MessageClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% MessageClientStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% MessageClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% MessageClientStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% MessageClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% MessageClient.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% MessageClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% MessageClient.exe

pause