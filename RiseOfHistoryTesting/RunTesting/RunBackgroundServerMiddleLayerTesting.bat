@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% BackgroundServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% BackgroundServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% BackgroundServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% BackgroundServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% BackgroundServerMiddleLayerTesting.exe

pause