@echo on
 
start /d %TheLastOverlordWin32DebugLib% BackgroundServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% BackgroundServer.exe
start /d %TheLastOverlordX64DebugLib% BackgroundServerD.exe
start /d %TheLastOverlordX64ReleaseLib% BackgroundServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% BackgroundServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% BackgroundServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% BackgroundServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% BackgroundServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% BackgroundServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% BackgroundServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% BackgroundServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% BackgroundServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% BackgroundServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% BackgroundServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% BackgroundServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% BackgroundServer.exe

pause