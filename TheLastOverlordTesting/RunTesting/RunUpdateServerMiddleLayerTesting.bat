@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% UpdateServerMiddleLayerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% UpdateServerMiddleLayerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% UpdateServerMiddleLayerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% UpdateServerMiddleLayerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% UpdateServerMiddleLayerTesting.exe

pause