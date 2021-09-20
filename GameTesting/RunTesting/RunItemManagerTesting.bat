@echo on
 
start /d %GameTestingWin32DebugLib% ItemManagerTestingD.exe
start /d %GameTestingWin32ReleaseLib% ItemManagerTesting.exe
start /d %GameTestingX64DebugLib% ItemManagerTestingD.exe
start /d %GameTestingX64ReleaseLib% ItemManagerTesting.exe
start /d %GameTestingStaticWin32DebugLib% ItemManagerTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% ItemManagerTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% ItemManagerTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% ItemManagerTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% ItemManagerTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% ItemManagerTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% ItemManagerTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% ItemManagerTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% ItemManagerTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% ItemManagerTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% ItemManagerTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% ItemManagerTestingStatic.exe

pause