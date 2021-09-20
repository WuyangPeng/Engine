@echo on
 
start /d %TheLastOverlordWin32DebugLib% GameClientD.exe
start /d %TheLastOverlordWin32ReleaseLib% GameClient.exe
start /d %TheLastOverlordX64DebugLib% GameClientD.exe
start /d %TheLastOverlordX64ReleaseLib% GameClient.exe
start /d %TheLastOverlordStaticWin32DebugLib% GameClientStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% GameClientStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% GameClientStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% GameClientStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% GameClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% GameClientStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% GameClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% GameClientStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% GameClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% GameClient.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% GameClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% GameClient.exe

pause