@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% LoginServerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% LoginServerMiddleLayerTesting.exe

pause