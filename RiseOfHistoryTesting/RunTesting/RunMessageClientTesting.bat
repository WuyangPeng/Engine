@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% MessageClientTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% MessageClientTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% MessageClientTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% MessageClientTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% MessageClientTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% MessageClientTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% MessageClientTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% MessageClientTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% MessageClientTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MessageClientTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% MessageClientTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MessageClientTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% MessageClientTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MessageClientTesting.exe

pause