@echo on
 
start /d %GameTestingWin32DebugLib% TeamTestingD.exe
start /d %GameTestingWin32ReleaseLib% TeamTesting.exe
start /d %GameTestingX64DebugLib% TeamTestingD.exe
start /d %GameTestingX64ReleaseLib% TeamTesting.exe
start /d %GameTestingStaticWin32DebugLib% TeamTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% TeamTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% TeamTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% TeamTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% TeamTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% TeamTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% TeamTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% TeamTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% TeamTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% TeamTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% TeamTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% TeamTestingStatic.exe

pause