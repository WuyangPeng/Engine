@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% MessageClientCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% MessageClientCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% MessageClientCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% MessageClientCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% MessageClientCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% MessageClientCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% MessageClientCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% MessageClientCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% MessageClientCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MessageClientCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% MessageClientCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MessageClientCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% MessageClientCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MessageClientCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% MessageClientCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MessageClientCoreTesting.exe

pause