@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% CrossServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% CrossServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% CrossServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% CrossServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% CrossServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% CrossServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% CrossServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% CrossServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% CrossServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% CrossServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% CrossServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% CrossServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% CrossServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% CrossServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% CrossServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% CrossServerMiddleLayerTesting.exe

pause