@echo on
 
start /d %RiseOfHistoryWin32DebugLib% PlayerServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% PlayerServer.exe
start /d %RiseOfHistoryX64DebugLib% PlayerServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% PlayerServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% PlayerServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% PlayerServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% PlayerServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% PlayerServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% PlayerServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% PlayerServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% PlayerServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% PlayerServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% PlayerServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% PlayerServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% PlayerServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% PlayerServer.exe

pause