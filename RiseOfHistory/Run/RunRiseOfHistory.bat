@echo on
 
start /d %RiseOfHistoryWin32DebugLib% RiseOfHistoryD.exe
start /d %RiseOfHistoryWin32ReleaseLib% RiseOfHistory.exe
start /d %RiseOfHistoryX64DebugLib% RiseOfHistoryD.exe
start /d %RiseOfHistoryX64ReleaseLib% RiseOfHistory.exe
start /d %RiseOfHistoryStaticWin32DebugLib% RiseOfHistoryStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% RiseOfHistoryStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% RiseOfHistoryStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% RiseOfHistoryStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% RiseOfHistoryStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% RiseOfHistoryStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% RiseOfHistoryStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% RiseOfHistoryStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% RiseOfHistoryD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% RiseOfHistory.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% RiseOfHistoryD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% RiseOfHistory.exe

pause