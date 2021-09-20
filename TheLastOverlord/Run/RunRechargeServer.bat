@echo on
 
start /d %TheLastOverlordWin32DebugLib% RechargeServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% RechargeServer.exe
start /d %TheLastOverlordX64DebugLib% RechargeServerD.exe
start /d %TheLastOverlordX64ReleaseLib% RechargeServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% RechargeServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% RechargeServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% RechargeServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% RechargeServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% RechargeServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% RechargeServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% RechargeServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% RechargeServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% RechargeServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% RechargeServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% RechargeServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% RechargeServer.exe

pause