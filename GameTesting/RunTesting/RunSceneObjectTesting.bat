@echo on
 
start /d %GameTestingWin32DebugLib% SceneObjectTestingD.exe
start /d %GameTestingWin32ReleaseLib% SceneObjectTesting.exe
start /d %GameTestingX64DebugLib% SceneObjectTestingD.exe
start /d %GameTestingX64ReleaseLib% SceneObjectTesting.exe
start /d %GameTestingStaticWin32DebugLib% SceneObjectTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% SceneObjectTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% SceneObjectTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% SceneObjectTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% SceneObjectTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% SceneObjectTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% SceneObjectTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% SceneObjectTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% SceneObjectTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% SceneObjectTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% SceneObjectTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% SceneObjectTestingStatic.exe

pause