@echo on
 
start /d %MillenniumHistoryWin32DebugLib% BackgroundServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% BackgroundServer.exe
start /d %MillenniumHistoryX64DebugLib% BackgroundServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% BackgroundServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% BackgroundServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% BackgroundServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% BackgroundServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% BackgroundServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% BackgroundServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% BackgroundServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% BackgroundServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% BackgroundServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% BackgroundServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% BackgroundServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% BackgroundServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% BackgroundServer.exe

pause