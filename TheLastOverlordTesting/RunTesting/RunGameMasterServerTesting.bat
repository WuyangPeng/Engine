@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% GameMasterServerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% GameMasterServerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% GameMasterServerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% GameMasterServerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% GameMasterServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% GameMasterServerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% GameMasterServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% GameMasterServerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% GameMasterServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% GameMasterServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% GameMasterServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% GameMasterServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% GameMasterServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% GameMasterServerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% GameMasterServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% GameMasterServerTesting.exe

pause