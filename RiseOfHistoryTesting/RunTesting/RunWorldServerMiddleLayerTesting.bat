@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% WorldServerMiddleLayerTesting.exe

pause