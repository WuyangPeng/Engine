@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% ChatServerCoreTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% ChatServerCoreTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% ChatServerCoreTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% ChatServerCoreTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% ChatServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% ChatServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% ChatServerCoreTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% ChatServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% ChatServerCoreTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% ChatServerCoreTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% ChatServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% ChatServerCoreTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% ChatServerCoreTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% ChatServerCoreTesting.exe

pause