@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% ServerManagerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% ServerManagerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% ServerManagerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% ServerManagerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% ServerManagerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% ServerManagerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% ServerManagerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% ServerManagerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% ServerManagerCoreTesting.exe

pause