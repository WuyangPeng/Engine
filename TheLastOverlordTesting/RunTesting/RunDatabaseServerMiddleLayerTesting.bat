@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% DatabaseServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% DatabaseServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% DatabaseServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% DatabaseServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% DatabaseServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% DatabaseServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% DatabaseServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% DatabaseServerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% DatabaseServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% DatabaseServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% DatabaseServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% DatabaseServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% DatabaseServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% DatabaseServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% DatabaseServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% DatabaseServerMiddleLayerTesting.exe

pause