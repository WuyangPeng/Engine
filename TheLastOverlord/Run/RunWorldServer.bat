@echo on
 
start /d %TheLastOverlordWin32DebugLib% WorldServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% WorldServer.exe
start /d %TheLastOverlordX64DebugLib% WorldServerD.exe
start /d %TheLastOverlordX64ReleaseLib% WorldServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% WorldServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% WorldServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% WorldServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% WorldServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% WorldServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% WorldServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% WorldServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% WorldServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% WorldServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% WorldServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% WorldServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% WorldServer.exe

pause