@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% FightingServerCoreTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% FightingServerCoreTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% FightingServerCoreTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% FightingServerCoreTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% FightingServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% FightingServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% FightingServerCoreTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% FightingServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% FightingServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% FightingServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% FightingServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% FightingServerCoreTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% FightingServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% FightingServerCoreTesting.exe

pause