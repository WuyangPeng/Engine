@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% RechargeServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% RechargeServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% RechargeServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% RechargeServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% RechargeServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% RechargeServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% RechargeServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% RechargeServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% RechargeServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% RechargeServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% RechargeServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% RechargeServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% RechargeServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% RechargeServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% RechargeServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% RechargeServerTesting.exe

pause