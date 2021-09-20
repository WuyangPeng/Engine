@echo on
 
start /d %GameTestingWin32DebugLib% RelationTestingD.exe
start /d %GameTestingWin32ReleaseLib% RelationTesting.exe
start /d %GameTestingX64DebugLib% RelationTestingD.exe
start /d %GameTestingX64ReleaseLib% RelationTesting.exe
start /d %GameTestingStaticWin32DebugLib% RelationTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% RelationTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% RelationTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% RelationTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% RelationTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% RelationTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% RelationTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% RelationTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% RelationTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% RelationTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% RelationTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% RelationTestingStatic.exe

pause