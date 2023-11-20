@echo on
 
start /d %RiseOfHistoryWin32DebugLib% ServerManagerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% ServerManager.exe
start /d %RiseOfHistoryX64DebugLib% ServerManagerD.exe
start /d %RiseOfHistoryX64ReleaseLib% ServerManager.exe
start /d %RiseOfHistoryStaticWin32DebugLib% ServerManagerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% ServerManagerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% ServerManagerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% ServerManagerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% ServerManagerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% ServerManagerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% ServerManagerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% ServerManagerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% ServerManagerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% ServerManager.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% ServerManagerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% ServerManager.exe

pause