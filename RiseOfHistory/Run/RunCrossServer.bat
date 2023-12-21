@echo on
 
start /d %RiseOfHistoryWin32DebugLib% CrossServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% CrossServer.exe
start /d %RiseOfHistoryX64DebugLib% CrossServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% CrossServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% CrossServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% CrossServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% CrossServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% CrossServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% CrossServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% CrossServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% CrossServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% CrossServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% CrossServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% CrossServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% CrossServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% CrossServer.exe

pause