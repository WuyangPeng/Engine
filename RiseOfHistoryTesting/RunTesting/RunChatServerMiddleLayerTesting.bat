@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% ChatServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% ChatServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% ChatServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% ChatServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% ChatServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% ChatServerMiddleLayerTesting.exe

pause