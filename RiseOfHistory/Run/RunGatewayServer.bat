@echo on
 
start /d %RiseOfHistoryWin32DebugLib% GatewayServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% GatewayServer.exe
start /d %RiseOfHistoryX64DebugLib% GatewayServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% GatewayServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% GatewayServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% GatewayServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% GatewayServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% GatewayServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% GatewayServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% GatewayServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% GatewayServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% GatewayServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% GatewayServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% GatewayServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% GatewayServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% GatewayServer.exe

pause