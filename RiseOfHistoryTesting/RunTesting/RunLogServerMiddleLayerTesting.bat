@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% LogServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% LogServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% LogServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% LogServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LogServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% LogServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LogServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% LogServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LogServerMiddleLayerTesting.exe

pause