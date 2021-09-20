@echo on
 
start /d %TheLastOverlordWin32DebugLib% LoginServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% LoginServer.exe
start /d %TheLastOverlordX64DebugLib% LoginServerD.exe
start /d %TheLastOverlordX64ReleaseLib% LoginServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% LoginServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% LoginServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% LoginServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% LoginServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% LoginServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% LoginServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% LoginServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% LoginServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% LoginServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% LoginServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% LoginServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% LoginServer.exe

pause