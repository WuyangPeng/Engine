@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% MessageClientTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% MessageClientTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% MessageClientTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% MessageClientTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% MessageClientTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% MessageClientTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% MessageClientTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% MessageClientTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% MessageClientTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MessageClientTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% MessageClientTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MessageClientTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% MessageClientTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MessageClientTesting.exe

pause