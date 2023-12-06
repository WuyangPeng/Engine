@echo on
 
start /d %MillenniumHistoryWin32DebugLib% GatewayServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% GatewayServer.exe
start /d %MillenniumHistoryX64DebugLib% GatewayServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% GatewayServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% GatewayServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% GatewayServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% GatewayServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% GatewayServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% GatewayServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% GatewayServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% GatewayServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% GatewayServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% GatewayServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% GatewayServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% GatewayServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% GatewayServer.exe

pause