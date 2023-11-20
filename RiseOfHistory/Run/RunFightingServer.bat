@echo on
 
start /d %RiseOfHistoryWin32DebugLib% FightingServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% FightingServer.exe
start /d %RiseOfHistoryX64DebugLib% FightingServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% FightingServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% FightingServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% FightingServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% FightingServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% FightingServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% FightingServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% FightingServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% FightingServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% FightingServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% FightingServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% FightingServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% FightingServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% FightingServer.exe

pause