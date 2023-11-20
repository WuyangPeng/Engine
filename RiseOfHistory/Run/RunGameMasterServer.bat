@echo on
 
start /d %RiseOfHistoryWin32DebugLib% GameMasterServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% GameMasterServer.exe
start /d %RiseOfHistoryX64DebugLib% GameMasterServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% GameMasterServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% GameMasterServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% GameMasterServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% GameMasterServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% GameMasterServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% GameMasterServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% GameMasterServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% GameMasterServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% GameMasterServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% GameMasterServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% GameMasterServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% GameMasterServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% GameMasterServer.exe

pause