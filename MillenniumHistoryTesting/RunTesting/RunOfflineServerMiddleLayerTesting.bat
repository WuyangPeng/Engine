@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% OfflineServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% OfflineServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerMiddleLayerTesting.exe

pause