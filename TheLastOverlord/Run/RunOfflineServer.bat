@echo on
 
start /d %TheLastOverlordWin32DebugLib% OfflineServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% OfflineServer.exe
start /d %TheLastOverlordX64DebugLib% OfflineServerD.exe
start /d %TheLastOverlordX64ReleaseLib% OfflineServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% OfflineServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% OfflineServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% OfflineServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% OfflineServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% OfflineServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% OfflineServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% OfflineServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% OfflineServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% OfflineServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% OfflineServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% OfflineServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% OfflineServer.exe

pause