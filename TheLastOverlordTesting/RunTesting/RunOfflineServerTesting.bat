@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% OfflineServerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% OfflineServerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% OfflineServerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% OfflineServerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% OfflineServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% OfflineServerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% OfflineServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% OfflineServerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% OfflineServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% OfflineServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerTesting.exe

pause