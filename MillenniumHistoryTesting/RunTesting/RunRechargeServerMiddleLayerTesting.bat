@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% RechargeServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% RechargeServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% RechargeServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% RechargeServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% RechargeServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% RechargeServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% RechargeServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% RechargeServerMiddleLayerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% RechargeServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% RechargeServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% RechargeServerMiddleLayerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% RechargeServerMiddleLayerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% RechargeServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% RechargeServerMiddleLayerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% RechargeServerMiddleLayerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% RechargeServerMiddleLayerTesting.exe

pause