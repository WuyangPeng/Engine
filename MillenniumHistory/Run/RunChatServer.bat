@echo on
 
start /d %MillenniumHistoryWin32DebugLib% ChatServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% ChatServer.exe
start /d %MillenniumHistoryX64DebugLib% ChatServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% ChatServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% ChatServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% ChatServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% ChatServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% ChatServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% ChatServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% ChatServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% ChatServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% ChatServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% ChatServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% ChatServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% ChatServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% ChatServer.exe

pause