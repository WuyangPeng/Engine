@echo on
 
start /d %GameTestingWin32DebugLib% ActivityTestingD.exe
start /d %GameTestingWin32ReleaseLib% ActivityTesting.exe
start /d %GameTestingX64DebugLib% ActivityTestingD.exe
start /d %GameTestingX64ReleaseLib% ActivityTesting.exe
start /d %GameTestingStaticWin32DebugLib% ActivityTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% ActivityTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% ActivityTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% ActivityTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% ActivityTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% ActivityTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% ActivityTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% ActivityTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% ActivityTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% ActivityTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% ActivityTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% ActivityTestingStatic.exe

pause