@echo on
 
start /d %GameTestingWin32DebugLib% QuestTestingD.exe
start /d %GameTestingWin32ReleaseLib% QuestTesting.exe
start /d %GameTestingX64DebugLib% QuestTestingD.exe
start /d %GameTestingX64ReleaseLib% QuestTesting.exe
start /d %GameTestingStaticWin32DebugLib% QuestTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% QuestTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% QuestTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% QuestTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% QuestTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% QuestTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% QuestTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% QuestTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% QuestTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% QuestTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% QuestTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% QuestTestingStatic.exe

pause