@echo on
 
start /d %TheLastOverlordWin32DebugLib% LeaderboardServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% LeaderboardServer.exe
start /d %TheLastOverlordX64DebugLib% LeaderboardServerD.exe
start /d %TheLastOverlordX64ReleaseLib% LeaderboardServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% LeaderboardServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% LeaderboardServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% LeaderboardServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% LeaderboardServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% LeaderboardServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% LeaderboardServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% LeaderboardServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% LeaderboardServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% LeaderboardServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% LeaderboardServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% LeaderboardServer.exe

pause