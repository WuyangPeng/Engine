@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% UpdateServerMiddleLayerTesting.exe

pause