@echo on
 
start /d %RiseOfHistoryWin32DebugLib% DatabaseServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% DatabaseServer.exe
start /d %RiseOfHistoryX64DebugLib% DatabaseServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% DatabaseServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% DatabaseServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% DatabaseServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% DatabaseServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% DatabaseServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% DatabaseServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% DatabaseServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% DatabaseServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% DatabaseServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% DatabaseServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% DatabaseServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% DatabaseServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% DatabaseServer.exe

pause