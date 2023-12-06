@echo on
 
start /d %MillenniumHistoryWin32DebugLib% ServerManagerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% ServerManager.exe
start /d %MillenniumHistoryX64DebugLib% ServerManagerD.exe
start /d %MillenniumHistoryX64ReleaseLib% ServerManager.exe
start /d %MillenniumHistoryStaticWin32DebugLib% ServerManagerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% ServerManagerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% ServerManagerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% ServerManagerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% ServerManagerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% ServerManagerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% ServerManagerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% ServerManagerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% ServerManagerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% ServerManager.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% ServerManagerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% ServerManager.exe

pause