@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% OfflineServerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% OfflineServerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% OfflineServerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% OfflineServerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% OfflineServerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% OfflineServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% OfflineServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerCoreTesting.exe

pause