@echo on
 
start /d %GameTestingWin32DebugLib% ArenaTestingD.exe
start /d %GameTestingWin32ReleaseLib% ArenaTesting.exe
start /d %GameTestingX64DebugLib% ArenaTestingD.exe
start /d %GameTestingX64ReleaseLib% ArenaTesting.exe
start /d %GameTestingStaticWin32DebugLib% ArenaTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% ArenaTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% ArenaTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% ArenaTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% ArenaTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% ArenaTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% ArenaTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% ArenaTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% ArenaTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% ArenaTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% ArenaTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% ArenaTestingStatic.exe

pause