@echo on
 
start /d %TheLastOverlordWin32DebugLib% ChatServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% ChatServer.exe
start /d %TheLastOverlordX64DebugLib% ChatServerD.exe
start /d %TheLastOverlordX64ReleaseLib% ChatServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% ChatServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% ChatServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% ChatServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% ChatServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% ChatServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% ChatServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% ChatServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% ChatServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% ChatServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% ChatServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% ChatServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% ChatServer.exe

pause