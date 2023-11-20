@echo on
 
start /d %RiseOfHistoryWin32DebugLib% MessageClientD.exe
start /d %RiseOfHistoryWin32ReleaseLib% MessageClient.exe
start /d %RiseOfHistoryX64DebugLib% MessageClientD.exe
start /d %RiseOfHistoryX64ReleaseLib% MessageClient.exe
start /d %RiseOfHistoryStaticWin32DebugLib% MessageClientStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% MessageClientStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% MessageClientStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% MessageClientStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% MessageClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% MessageClientStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% MessageClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% MessageClientStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% MessageClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% MessageClient.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% MessageClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% MessageClient.exe

pause