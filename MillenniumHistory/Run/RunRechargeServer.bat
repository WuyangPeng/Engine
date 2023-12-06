@echo on
 
start /d %MillenniumHistoryWin32DebugLib% RechargeServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% RechargeServer.exe
start /d %MillenniumHistoryX64DebugLib% RechargeServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% RechargeServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% RechargeServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% RechargeServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% RechargeServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% RechargeServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% RechargeServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% RechargeServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% RechargeServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% RechargeServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% RechargeServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% RechargeServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% RechargeServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% RechargeServer.exe

pause