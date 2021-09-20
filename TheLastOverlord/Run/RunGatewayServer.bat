@echo on
 
start /d %TheLastOverlordWin32DebugLib% GatewayServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% GatewayServer.exe
start /d %TheLastOverlordX64DebugLib% GatewayServerD.exe
start /d %TheLastOverlordX64ReleaseLib% GatewayServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% GatewayServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% GatewayServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% GatewayServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% GatewayServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% GatewayServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% GatewayServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% GatewayServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% GatewayServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% GatewayServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% GatewayServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% GatewayServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% GatewayServer.exe

pause