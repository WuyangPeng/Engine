@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% GameClientTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% GameClientTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% GameClientTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% GameClientTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% GameClientTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% GameClientTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% GameClientTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% GameClientTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% GameClientTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% GameClientTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% GameClientTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% GameClientTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% GameClientTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% GameClientTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% GameClientTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% GameClientTesting.exe

pause