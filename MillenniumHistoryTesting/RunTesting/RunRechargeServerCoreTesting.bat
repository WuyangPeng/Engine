@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% RechargeServerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% RechargeServerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% RechargeServerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% RechargeServerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% RechargeServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% RechargeServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% RechargeServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% RechargeServerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% RechargeServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% RechargeServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% RechargeServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% RechargeServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% RechargeServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% RechargeServerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% RechargeServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% RechargeServerCoreTesting.exe

pause