@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerMiddleLayerTesting.exe

pause