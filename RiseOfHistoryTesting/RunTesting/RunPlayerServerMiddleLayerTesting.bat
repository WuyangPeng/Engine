@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% PlayerServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% PlayerServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% PlayerServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% PlayerServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% PlayerServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% PlayerServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% PlayerServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% PlayerServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% PlayerServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% PlayerServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% PlayerServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% PlayerServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% PlayerServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% PlayerServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% PlayerServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% PlayerServerMiddleLayerTesting.exe

pause