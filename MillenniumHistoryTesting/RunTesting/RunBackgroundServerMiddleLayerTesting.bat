@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% BackgroundServerMiddleLayerTesting.exe

pause