@echo on
 
start /d %MillenniumHistoryWin32DebugLib% CrossServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% CrossServer.exe
start /d %MillenniumHistoryX64DebugLib% CrossServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% CrossServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% CrossServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% CrossServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% CrossServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% CrossServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% CrossServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% CrossServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% CrossServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% CrossServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% CrossServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% CrossServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% CrossServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% CrossServer.exe

pause