@echo on
 
start /d %TheLastOverlordWin32DebugLib% CrossServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% CrossServer.exe
start /d %TheLastOverlordX64DebugLib% CrossServerD.exe
start /d %TheLastOverlordX64ReleaseLib% CrossServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% CrossServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% CrossServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% CrossServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% CrossServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% CrossServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% CrossServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% CrossServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% CrossServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% CrossServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% CrossServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% CrossServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% CrossServer.exe

pause