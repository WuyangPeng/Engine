@echo on
 
start /d %TheLastOverlordWin32DebugLib% CorssServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% CorssServer.exe
start /d %TheLastOverlordX64DebugLib% CorssServerD.exe
start /d %TheLastOverlordX64ReleaseLib% CorssServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% CorssServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% CorssServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% CorssServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% CorssServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% CorssServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% CorssServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% CorssServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% CorssServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% CorssServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% CorssServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% CorssServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% CorssServer.exe

pause