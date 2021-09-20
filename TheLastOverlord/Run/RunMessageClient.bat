@echo on
 
start /d %TheLastOverlordWin32DebugLib% MessageClientD.exe
start /d %TheLastOverlordWin32ReleaseLib% MessageClient.exe
start /d %TheLastOverlordX64DebugLib% MessageClientD.exe
start /d %TheLastOverlordX64ReleaseLib% MessageClient.exe
start /d %TheLastOverlordStaticWin32DebugLib% MessageClientStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% MessageClientStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% MessageClientStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% MessageClientStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% MessageClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% MessageClientStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% MessageClientStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% MessageClientStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% MessageClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% MessageClient.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% MessageClientD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% MessageClient.exe

pause