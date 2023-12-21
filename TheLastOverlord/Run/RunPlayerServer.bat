@echo on
 
start /d %TheLastOverlordWin32DebugLib% PlayerServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% PlayerServer.exe
start /d %TheLastOverlordX64DebugLib% PlayerServerD.exe
start /d %TheLastOverlordX64ReleaseLib% PlayerServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% PlayerServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% PlayerServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% PlayerServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% PlayerServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% PlayerServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% PlayerServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% PlayerServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% PlayerServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% PlayerServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% PlayerServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% PlayerServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% PlayerServer.exe

pause