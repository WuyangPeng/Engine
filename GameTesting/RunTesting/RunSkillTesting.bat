@echo on
 
start /d %GameTestingWin32DebugLib% SkillTestingD.exe
start /d %GameTestingWin32ReleaseLib% SkillTesting.exe
start /d %GameTestingX64DebugLib% SkillTestingD.exe
start /d %GameTestingX64ReleaseLib% SkillTesting.exe
start /d %GameTestingStaticWin32DebugLib% SkillTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% SkillTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% SkillTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% SkillTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% SkillTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% SkillTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% SkillTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% SkillTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% SkillTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% SkillTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% SkillTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% SkillTestingStatic.exe

pause