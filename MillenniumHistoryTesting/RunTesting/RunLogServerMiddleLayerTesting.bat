@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% LogServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% LogServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% LogServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% LogServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% LogServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LogServerMiddleLayerTesting.exe

pause