@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% MessageClientMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% MessageClientMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% MessageClientMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% MessageClientMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% MessageClientMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% MessageClientMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% MessageClientMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% MessageClientMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% MessageClientMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MessageClientMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% MessageClientMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MessageClientMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% MessageClientMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MessageClientMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% MessageClientMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MessageClientMiddleLayerTesting.exe

pause