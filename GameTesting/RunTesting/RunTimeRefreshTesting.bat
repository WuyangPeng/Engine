@echo on
 
start /d %GameTestingWin32DebugLib% TimeRefreshTestingD.exe
start /d %GameTestingWin32ReleaseLib% TimeRefreshTesting.exe
start /d %GameTestingX64DebugLib% TimeRefreshTestingD.exe
start /d %GameTestingX64ReleaseLib% TimeRefreshTesting.exe
start /d %GameTestingStaticWin32DebugLib% TimeRefreshTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% TimeRefreshTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% TimeRefreshTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% TimeRefreshTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% TimeRefreshTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% TimeRefreshTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% TimeRefreshTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% TimeRefreshTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% TimeRefreshTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% TimeRefreshTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% TimeRefreshTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% TimeRefreshTestingStatic.exe

pause