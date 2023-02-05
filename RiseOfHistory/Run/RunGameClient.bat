@echo on
 
start /d %RiseOfHistoryWin32DebugLib% GameClientD.exe
start /d %RiseOfHistoryWin32ReleaseLib% GameClient.exe
start /d %RiseOfHistoryX64DebugLib% GameClientD.exe
start /d %RiseOfHistoryX64ReleaseLib% GameClient.exe
start /d %RiseOfHistoryStaticWin32DebugLib% GameClientStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% GameClientStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% GameClientStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% GameClientStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% GameClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% GameClientStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% GameClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% GameClientStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% GameClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% GameClient.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% GameClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% GameClient.exe

pause