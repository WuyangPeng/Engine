@echo on
 
start /d %TheLastOverlordTestingWin32DebugLib% LogServerTestingD.exe
start /d %TheLastOverlordTestingWin32ReleaseLib% LogServerTesting.exe
start /d %TheLastOverlordTestingX64DebugLib% LogServerTestingD.exe
start /d %TheLastOverlordTestingX64ReleaseLib% LogServerTesting.exe
start /d %TheLastOverlordTestingStaticWin32DebugLib% LogServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticWin32ReleaseLib% LogServerTestingStatic.exe
start /d %TheLastOverlordTestingStaticX64DebugLib% LogServerTestingStaticD.exe
start /d %TheLastOverlordTestingStaticX64ReleaseLib% LogServerTestingStatic.exe

start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib% LogServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib% LogServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib% LogServerTestingStaticD.exe
start /d %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib% LogServerTestingStatic.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib% LogServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib% LogServerTesting.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib% LogServerTestingD.exe
start /d %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib% LogServerTesting.exe

pause