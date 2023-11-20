@echo on
 
start /d %RiseOfHistoryWin32DebugLib% WorldServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% WorldServer.exe
start /d %RiseOfHistoryX64DebugLib% WorldServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% WorldServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% WorldServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% WorldServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% WorldServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% WorldServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% WorldServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% WorldServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% WorldServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% WorldServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% WorldServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% WorldServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% WorldServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% WorldServer.exe

pause