@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% DatabaseGenerateCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% DatabaseGenerateCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% DatabaseGenerateCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% DatabaseGenerateCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% DatabaseGenerateCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% DatabaseGenerateCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% DatabaseGenerateCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% DatabaseGenerateCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% DatabaseGenerateCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% DatabaseGenerateCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% DatabaseGenerateCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% DatabaseGenerateCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% DatabaseGenerateCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% DatabaseGenerateCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% DatabaseGenerateCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% DatabaseGenerateCoreTesting.exe

pause