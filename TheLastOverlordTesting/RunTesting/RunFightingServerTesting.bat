@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% FightingServerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% FightingServerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% FightingServerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% FightingServerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% FightingServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% FightingServerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% FightingServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% FightingServerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% FightingServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% FightingServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% FightingServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% FightingServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% FightingServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% FightingServerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% FightingServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% FightingServerTesting.exe

pause