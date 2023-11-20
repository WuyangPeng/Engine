@echo on
 
start /d %RiseOfHistoryWin32DebugLib% GameServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% GameServer.exe
start /d %RiseOfHistoryX64DebugLib% GameServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% GameServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% GameServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% GameServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% GameServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% GameServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% GameServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% GameServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% GameServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% GameServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% GameServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% GameServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% GameServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% GameServer.exe

pause