@echo on
 
start /d %MillenniumHistoryWin32DebugLib% OfflineServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% OfflineServer.exe
start /d %MillenniumHistoryX64DebugLib% OfflineServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% OfflineServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% OfflineServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% OfflineServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% OfflineServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% OfflineServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% OfflineServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% OfflineServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% OfflineServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% OfflineServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% OfflineServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% OfflineServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% OfflineServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% OfflineServer.exe

pause