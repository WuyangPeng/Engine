@echo on
 
start /d %TheLastOverlordWin32DebugLib% UpdateServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% UpdateServer.exe
start /d %TheLastOverlordX64DebugLib% UpdateServerD.exe
start /d %TheLastOverlordX64ReleaseLib% UpdateServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% UpdateServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% UpdateServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% UpdateServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% UpdateServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% UpdateServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% UpdateServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% UpdateServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% UpdateServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% UpdateServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% UpdateServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% UpdateServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% UpdateServer.exe

pause