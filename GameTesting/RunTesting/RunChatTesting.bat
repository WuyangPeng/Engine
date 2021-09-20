@echo on
 
start /d %GameTestingWin32DebugLib% ChatTestingD.exe
start /d %GameTestingWin32ReleaseLib% ChatTesting.exe
start /d %GameTestingX64DebugLib% ChatTestingD.exe
start /d %GameTestingX64ReleaseLib% ChatTesting.exe
start /d %GameTestingStaticWin32DebugLib% ChatTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% ChatTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% ChatTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% ChatTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% ChatTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% ChatTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% ChatTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% ChatTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% ChatTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% ChatTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% ChatTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% ChatTestingStatic.exe

pause