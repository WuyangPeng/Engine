@echo on
 
start /d %MillenniumHistoryWin32DebugLib% PlayerServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% PlayerServer.exe
start /d %MillenniumHistoryX64DebugLib% PlayerServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% PlayerServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% PlayerServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% PlayerServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% PlayerServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% PlayerServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% PlayerServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% PlayerServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% PlayerServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% PlayerServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% PlayerServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% PlayerServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% PlayerServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% PlayerServer.exe

pause