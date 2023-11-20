@echo on
 
start /d %RiseOfHistoryWin32DebugLib% LoginServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% LoginServer.exe
start /d %RiseOfHistoryX64DebugLib% LoginServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% LoginServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% LoginServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% LoginServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% LoginServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% LoginServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% LoginServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% LoginServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% LoginServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% LoginServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% LoginServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% LoginServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% LoginServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% LoginServer.exe

pause