@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% MessageClientTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% MessageClientTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% MessageClientTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% MessageClientTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% MessageClientTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% MessageClientTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% MessageClientTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% MessageClientTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% MessageClientTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% MessageClientTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% MessageClientTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% MessageClientTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% MessageClientTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% MessageClientTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% MessageClientTesting.exe

pause