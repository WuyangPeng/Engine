@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% PlayerServerCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% PlayerServerCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% PlayerServerCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% PlayerServerCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% PlayerServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% PlayerServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% PlayerServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% PlayerServerCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% PlayerServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% PlayerServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% PlayerServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% PlayerServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% PlayerServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% PlayerServerCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% PlayerServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% PlayerServerCoreTesting.exe

pause