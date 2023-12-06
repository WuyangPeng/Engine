@echo on
 
start /d %MillenniumHistoryWin32DebugLib% BackgroundClientD.exe
start /d %MillenniumHistoryWin32ReleaseLib% BackgroundClient.exe
start /d %MillenniumHistoryX64DebugLib% BackgroundClientD.exe
start /d %MillenniumHistoryX64ReleaseLib% BackgroundClient.exe
start /d %MillenniumHistoryStaticWin32DebugLib% BackgroundClientStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% BackgroundClientStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% BackgroundClientStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% BackgroundClientStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% BackgroundClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% BackgroundClientStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% BackgroundClientStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% BackgroundClientStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% BackgroundClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% BackgroundClient.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% BackgroundClientD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% BackgroundClient.exe

pause