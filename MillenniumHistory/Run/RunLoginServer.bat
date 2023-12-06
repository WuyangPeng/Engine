@echo on
 
start /d %MillenniumHistoryWin32DebugLib% LoginServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% LoginServer.exe
start /d %MillenniumHistoryX64DebugLib% LoginServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% LoginServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% LoginServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% LoginServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% LoginServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% LoginServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% LoginServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% LoginServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% LoginServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% LoginServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% LoginServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% LoginServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% LoginServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% LoginServer.exe

pause