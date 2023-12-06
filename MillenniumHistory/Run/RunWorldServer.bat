@echo on
 
start /d %MillenniumHistoryWin32DebugLib% WorldServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% WorldServer.exe
start /d %MillenniumHistoryX64DebugLib% WorldServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% WorldServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% WorldServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% WorldServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% WorldServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% WorldServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% WorldServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% WorldServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% WorldServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% WorldServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% WorldServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% WorldServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% WorldServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% WorldServer.exe

pause