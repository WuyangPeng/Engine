@echo on
 
start /d %GameTestingWin32DebugLib% UserInfoTestingD.exe
start /d %GameTestingWin32ReleaseLib% UserInfoTesting.exe
start /d %GameTestingX64DebugLib% UserInfoTestingD.exe
start /d %GameTestingX64ReleaseLib% UserInfoTesting.exe
start /d %GameTestingStaticWin32DebugLib% UserInfoTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% UserInfoTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% UserInfoTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% UserInfoTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% UserInfoTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% UserInfoTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% UserInfoTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% UserInfoTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% UserInfoTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% UserInfoTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% UserInfoTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% UserInfoTestingStatic.exe

pause