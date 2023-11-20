@echo on
 
start /d %RiseOfHistoryWin32DebugLib% RechargeServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% RechargeServer.exe
start /d %RiseOfHistoryX64DebugLib% RechargeServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% RechargeServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% RechargeServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% RechargeServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% RechargeServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% RechargeServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% RechargeServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% RechargeServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% RechargeServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% RechargeServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% RechargeServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% RechargeServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% RechargeServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% RechargeServer.exe

pause