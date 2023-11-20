@echo on
 
start /d %RiseOfHistoryWin32DebugLib% LogServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% LogServer.exe
start /d %RiseOfHistoryX64DebugLib% LogServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% LogServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% LogServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% LogServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% LogServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% LogServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% LogServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% LogServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% LogServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% LogServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% LogServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% LogServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% LogServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% LogServer.exe

pause