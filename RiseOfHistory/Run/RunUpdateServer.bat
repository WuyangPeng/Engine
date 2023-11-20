@echo on
 
start /d %RiseOfHistoryWin32DebugLib% UpdateServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% UpdateServer.exe
start /d %RiseOfHistoryX64DebugLib% UpdateServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% UpdateServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% UpdateServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% UpdateServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% UpdateServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% UpdateServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% UpdateServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% UpdateServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% UpdateServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% UpdateServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% UpdateServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% UpdateServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% UpdateServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% UpdateServer.exe

pause