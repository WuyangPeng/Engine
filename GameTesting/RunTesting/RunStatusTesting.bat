@echo on
 
start /d %GameTestingWin32DebugLib% StatusTestingD.exe
start /d %GameTestingWin32ReleaseLib% StatusTesting.exe
start /d %GameTestingX64DebugLib% StatusTestingD.exe
start /d %GameTestingX64ReleaseLib% StatusTesting.exe
start /d %GameTestingStaticWin32DebugLib% StatusTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% StatusTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% StatusTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% StatusTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% StatusTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% StatusTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% StatusTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% StatusTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% StatusTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% StatusTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% StatusTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% StatusTestingStatic.exe

pause