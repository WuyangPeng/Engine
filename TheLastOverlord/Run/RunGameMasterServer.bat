@echo on
 
start /d %TheLastOverlordWin32DebugLib% GameMasterServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% GameMasterServer.exe
start /d %TheLastOverlordX64DebugLib% GameMasterServerD.exe
start /d %TheLastOverlordX64ReleaseLib% GameMasterServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% GameMasterServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% GameMasterServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% GameMasterServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% GameMasterServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% GameMasterServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% GameMasterServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% GameMasterServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% GameMasterServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% GameMasterServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% GameMasterServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% GameMasterServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% GameMasterServer.exe

pause