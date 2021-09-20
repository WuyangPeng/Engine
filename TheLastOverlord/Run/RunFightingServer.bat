@echo on
 
start /d %TheLastOverlordWin32DebugLib% FightingServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% FightingServer.exe
start /d %TheLastOverlordX64DebugLib% FightingServerD.exe
start /d %TheLastOverlordX64ReleaseLib% FightingServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% FightingServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% FightingServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% FightingServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% FightingServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% FightingServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% FightingServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% FightingServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% FightingServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% FightingServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% FightingServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% FightingServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% FightingServer.exe

pause