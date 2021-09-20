@echo on
 
start /d %TheLastOverlordWin32DebugLib% GameServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% GameServer.exe
start /d %TheLastOverlordX64DebugLib% GameServerD.exe
start /d %TheLastOverlordX64ReleaseLib% GameServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% GameServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% GameServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% GameServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% GameServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% GameServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% GameServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% GameServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% GameServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% GameServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% GameServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% GameServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% GameServer.exe

pause