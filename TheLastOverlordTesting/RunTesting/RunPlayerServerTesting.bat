@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% PlayerServerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% PlayerServerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% PlayerServerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% PlayerServerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% PlayerServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% PlayerServerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% PlayerServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% PlayerServerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% PlayerServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% PlayerServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% PlayerServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% PlayerServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% PlayerServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% PlayerServerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% PlayerServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% PlayerServerTesting.exe

pause