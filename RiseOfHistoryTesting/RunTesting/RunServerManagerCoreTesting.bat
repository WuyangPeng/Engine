@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% ServerManagerCoreTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% ServerManagerCoreTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% ServerManagerCoreTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% ServerManagerCoreTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% ServerManagerCoreTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% ServerManagerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% ServerManagerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% ServerManagerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% ServerManagerCoreTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% ServerManagerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% ServerManagerCoreTesting.exe

pause