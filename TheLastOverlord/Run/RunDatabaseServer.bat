@echo on
 
start /d %TheLastOverlordWin32DebugLib% DatabaseServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% DatabaseServer.exe
start /d %TheLastOverlordX64DebugLib% DatabaseServerD.exe
start /d %TheLastOverlordX64ReleaseLib% DatabaseServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% DatabaseServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% DatabaseServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% DatabaseServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% DatabaseServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% DatabaseServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% DatabaseServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% DatabaseServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% DatabaseServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% DatabaseServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% DatabaseServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% DatabaseServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% DatabaseServer.exe

pause