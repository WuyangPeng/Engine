@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% LogServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% LogServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% LogServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% LogServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% LogServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% LogServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% LogServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% LogServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% LogServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% LogServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% LogServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% LogServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% LogServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% LogServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% LogServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% LogServerTesting.exe

pause