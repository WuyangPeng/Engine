@echo on
 
start /d %RiseOfHistoryWin32DebugLib% OfflineServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% OfflineServer.exe
start /d %RiseOfHistoryX64DebugLib% OfflineServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% OfflineServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% OfflineServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% OfflineServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% OfflineServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% OfflineServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% OfflineServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% OfflineServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% OfflineServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% OfflineServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% OfflineServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% OfflineServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% OfflineServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% OfflineServer.exe

pause