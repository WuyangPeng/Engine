@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% ServerManagerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% ServerManagerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% ServerManagerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% ServerManagerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% ServerManagerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% ServerManagerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% ServerManagerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% ServerManagerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% ServerManagerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% ServerManagerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% ServerManagerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% ServerManagerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% ServerManagerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% ServerManagerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% ServerManagerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% ServerManagerMiddleLayerTesting.exe

pause