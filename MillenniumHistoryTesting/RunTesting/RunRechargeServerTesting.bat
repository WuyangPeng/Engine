@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% RechargeServerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% RechargeServerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% RechargeServerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% RechargeServerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% RechargeServerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% RechargeServerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% RechargeServerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% RechargeServerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% RechargeServerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% RechargeServerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% RechargeServerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% RechargeServerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% RechargeServerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% RechargeServerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% RechargeServerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% RechargeServerTesting.exe

pause