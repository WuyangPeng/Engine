@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% OfflineServerCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% OfflineServerCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% OfflineServerCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% OfflineServerCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% OfflineServerCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% OfflineServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerCoreTesting.exe

pause