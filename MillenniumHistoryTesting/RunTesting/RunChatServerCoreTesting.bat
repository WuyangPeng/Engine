@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% ChatServerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% ChatServerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% ChatServerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% ChatServerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% ChatServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% ChatServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% ChatServerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% ChatServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% ChatServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% ChatServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% ChatServerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% ChatServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% ChatServerCoreTesting.exe

pause