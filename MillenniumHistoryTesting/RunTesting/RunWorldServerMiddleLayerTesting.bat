@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% WorldServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% WorldServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% WorldServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% WorldServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% WorldServerMiddleLayerTesting.exe

pause