@echo on
 
start /d %GameTestingWin32DebugLib% SceneTestingD.exe
start /d %GameTestingWin32ReleaseLib% SceneTesting.exe
start /d %GameTestingX64DebugLib% SceneTestingD.exe
start /d %GameTestingX64ReleaseLib% SceneTesting.exe
start /d %GameTestingStaticWin32DebugLib% SceneTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% SceneTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% SceneTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% SceneTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% SceneTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% SceneTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% SceneTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% SceneTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% SceneTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% SceneTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% SceneTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% SceneTestingStatic.exe

pause