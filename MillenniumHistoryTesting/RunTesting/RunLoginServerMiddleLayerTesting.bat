@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% LoginServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% LoginServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LoginServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LoginServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% LoginServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LoginServerMiddleLayerTesting.exe

pause