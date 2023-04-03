@echo on
 
start /d %MillenniumHistoryWin32DebugLib% MillenniumHistoryD.exe
start /d %MillenniumHistoryWin32ReleaseLib% MillenniumHistory.exe
start /d %MillenniumHistoryX64DebugLib% MillenniumHistoryD.exe
start /d %MillenniumHistoryX64ReleaseLib% MillenniumHistory.exe
start /d %MillenniumHistoryStaticWin32DebugLib% MillenniumHistoryStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% MillenniumHistoryStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% MillenniumHistoryStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% MillenniumHistoryStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% MillenniumHistoryStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% MillenniumHistoryStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% MillenniumHistoryStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% MillenniumHistoryStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% MillenniumHistoryD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% MillenniumHistory.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% MillenniumHistoryD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% MillenniumHistory.exe

pause