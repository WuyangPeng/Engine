@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% LoginServerCoreTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% LoginServerCoreTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% LoginServerCoreTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% LoginServerCoreTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% LoginServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% LoginServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% LoginServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% LoginServerCoreTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% LoginServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LoginServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% LoginServerCoreTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LoginServerCoreTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% LoginServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LoginServerCoreTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% LoginServerCoreTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LoginServerCoreTesting.exe

pause