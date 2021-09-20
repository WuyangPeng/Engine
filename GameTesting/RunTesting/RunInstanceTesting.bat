@echo on
 
start /d %GameTestingWin32DebugLib% InstanceTestingD.exe
start /d %GameTestingWin32ReleaseLib% InstanceTesting.exe
start /d %GameTestingX64DebugLib% InstanceTestingD.exe
start /d %GameTestingX64ReleaseLib% InstanceTesting.exe
start /d %GameTestingStaticWin32DebugLib% InstanceTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% InstanceTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% InstanceTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% InstanceTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% InstanceTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% InstanceTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% InstanceTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% InstanceTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% InstanceTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% InstanceTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% InstanceTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% InstanceTestingStatic.exe

pause