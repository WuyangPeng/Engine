@echo on
 
start /d %TheLastOverlordWin32DebugLib% LogServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% LogServer.exe
start /d %TheLastOverlordX64DebugLib% LogServerD.exe
start /d %TheLastOverlordX64ReleaseLib% LogServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% LogServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% LogServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% LogServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% LogServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% LogServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% LogServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% LogServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% LogServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% LogServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% LogServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% LogServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% LogServer.exe

pause