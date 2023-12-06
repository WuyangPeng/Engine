@echo on
 
start /d %MillenniumHistoryWin32DebugLib% UpdateServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% UpdateServer.exe
start /d %MillenniumHistoryX64DebugLib% UpdateServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% UpdateServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% UpdateServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% UpdateServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% UpdateServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% UpdateServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% UpdateServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% UpdateServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% UpdateServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% UpdateServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% UpdateServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% UpdateServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% UpdateServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% UpdateServer.exe

pause