@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% FightingServerCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% FightingServerCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% FightingServerCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% FightingServerCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% FightingServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% FightingServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% FightingServerCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% FightingServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% FightingServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% FightingServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% FightingServerCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% FightingServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% FightingServerCoreTesting.exe

pause