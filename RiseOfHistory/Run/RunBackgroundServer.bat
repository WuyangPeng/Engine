@echo on
 
start /d %RiseOfHistoryWin32DebugLib% BackgroundServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% BackgroundServer.exe
start /d %RiseOfHistoryX64DebugLib% BackgroundServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% BackgroundServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% BackgroundServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% BackgroundServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% BackgroundServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% BackgroundServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% BackgroundServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% BackgroundServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% BackgroundServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% BackgroundServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% BackgroundServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% BackgroundServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% BackgroundServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% BackgroundServer.exe

pause