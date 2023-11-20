@echo on
 
start /d %RiseOfHistoryWin32DebugLib% BackgroundClientD.exe
start /d %RiseOfHistoryWin32ReleaseLib% BackgroundClient.exe
start /d %RiseOfHistoryX64DebugLib% BackgroundClientD.exe
start /d %RiseOfHistoryX64ReleaseLib% BackgroundClient.exe
start /d %RiseOfHistoryStaticWin32DebugLib% BackgroundClientStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% BackgroundClientStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% BackgroundClientStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% BackgroundClientStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% BackgroundClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% BackgroundClientStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% BackgroundClientStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% BackgroundClientStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% BackgroundClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% BackgroundClient.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% BackgroundClientD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% BackgroundClient.exe

pause