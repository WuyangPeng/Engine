@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% GatewayServerCoreTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% GatewayServerCoreTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% GatewayServerCoreTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% GatewayServerCoreTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% GatewayServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% GatewayServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% GatewayServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% GatewayServerCoreTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% GatewayServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% GatewayServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% GatewayServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% GatewayServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% GatewayServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% GatewayServerCoreTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% GatewayServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% GatewayServerCoreTesting.exe

pause