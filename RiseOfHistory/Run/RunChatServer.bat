@echo on
 
start /d %RiseOfHistoryWin32DebugLib% ChatServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% ChatServer.exe
start /d %RiseOfHistoryX64DebugLib% ChatServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% ChatServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% ChatServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% ChatServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% ChatServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% ChatServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% ChatServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% ChatServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% ChatServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% ChatServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% ChatServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% ChatServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% ChatServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% ChatServer.exe

pause