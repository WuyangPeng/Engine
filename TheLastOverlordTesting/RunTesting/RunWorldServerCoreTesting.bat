@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% WorldServerCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% WorldServerCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% WorldServerCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% WorldServerCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% WorldServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% WorldServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% WorldServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% WorldServerCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% WorldServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% WorldServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% WorldServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% WorldServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% WorldServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% WorldServerCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% WorldServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% WorldServerCoreTesting.exe

pause