@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% GameServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% GameServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% GameServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% GameServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% GameServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% GameServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% GameServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% GameServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% GameServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% GameServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% GameServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% GameServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% GameServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% GameServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% GameServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% GameServerMiddleLayerTesting.exe

pause