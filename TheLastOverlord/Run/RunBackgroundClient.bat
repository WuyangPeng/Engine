@echo on
 
start /d %TheLastOverlordWin32DebugLib% BackgroundClientD.exe
start /d %TheLastOverlordWin32ReleaseLib% BackgroundClient.exe
start /d %TheLastOverlordX64DebugLib% BackgroundClientD.exe
start /d %TheLastOverlordX64ReleaseLib% BackgroundClient.exe
start /d %TheLastOverlordStaticWin32DebugLib% BackgroundClientStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% BackgroundClientStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% BackgroundClientStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% BackgroundClientStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% BackgroundClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% BackgroundClientStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% BackgroundClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% BackgroundClientStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% BackgroundClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% BackgroundClient.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% BackgroundClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% BackgroundClient.exe

pause