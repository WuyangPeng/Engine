@echo on
 
start /d %MillenniumHistoryWin32DebugLib% DatabaseServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% DatabaseServer.exe
start /d %MillenniumHistoryX64DebugLib% DatabaseServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% DatabaseServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% DatabaseServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% DatabaseServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% DatabaseServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% DatabaseServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% DatabaseServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% DatabaseServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% DatabaseServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% DatabaseServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% DatabaseServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% DatabaseServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% DatabaseServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% DatabaseServer.exe

pause