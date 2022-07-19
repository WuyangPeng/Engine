@echo on
 
start /d %GameTestingWin32DebugLib% InterfaceTestingD.exe
start /d %GameTestingWin32ReleaseLib% InterfaceTesting.exe
start /d %GameTestingX64DebugLib% InterfaceTestingD.exe
start /d %GameTestingX64ReleaseLib% InterfaceTesting.exe
start /d %GameTestingStaticWin32DebugLib% InterfaceTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% InterfaceTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% InterfaceTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% InterfaceTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% InterfaceTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% InterfaceTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% InterfaceTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% InterfaceTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% InterfaceTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% InterfaceTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% InterfaceTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% InterfaceTestingStatic.exe

pause