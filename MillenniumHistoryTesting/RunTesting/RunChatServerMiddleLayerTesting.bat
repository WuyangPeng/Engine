@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% ChatServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% ChatServerMiddleLayerTesting.exe

pause