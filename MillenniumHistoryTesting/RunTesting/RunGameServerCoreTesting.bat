@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% GameServerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% GameServerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% GameServerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% GameServerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% GameServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% GameServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% GameServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% GameServerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% GameServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% GameServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% GameServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% GameServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% GameServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% GameServerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% GameServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% GameServerCoreTesting.exe

pause