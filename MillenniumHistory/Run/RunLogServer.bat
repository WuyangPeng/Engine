@echo on
 
start /d %MillenniumHistoryWin32DebugLib% LogServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% LogServer.exe
start /d %MillenniumHistoryX64DebugLib% LogServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% LogServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% LogServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% LogServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% LogServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% LogServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% LogServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% LogServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% LogServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% LogServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% LogServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% LogServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% LogServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% LogServer.exe

pause