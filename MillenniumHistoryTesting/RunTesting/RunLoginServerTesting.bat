@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% LoginServerTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% LoginServerTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% LoginServerTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% LoginServerTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% LoginServerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% LoginServerTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% LoginServerTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% LoginServerTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% LoginServerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LoginServerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% LoginServerTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LoginServerTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% LoginServerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LoginServerTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% LoginServerTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LoginServerTesting.exe

pause