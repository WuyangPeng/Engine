@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% WorldServerMiddleLayerTesting.exe

pause