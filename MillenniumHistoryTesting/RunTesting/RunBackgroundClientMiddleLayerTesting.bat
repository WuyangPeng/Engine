@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% BackgroundClientMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% BackgroundClientMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% BackgroundClientMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% BackgroundClientMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% BackgroundClientMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% BackgroundClientMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% BackgroundClientMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% BackgroundClientMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% BackgroundClientMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% BackgroundClientMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% BackgroundClientMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% BackgroundClientMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% BackgroundClientMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% BackgroundClientMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% BackgroundClientMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% BackgroundClientMiddleLayerTesting.exe

pause