@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% CrossServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% CrossServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% CrossServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% CrossServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% CrossServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% CrossServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% CrossServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% CrossServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% CrossServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% CrossServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% CrossServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% CrossServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% CrossServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% CrossServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% CrossServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% CrossServerTesting.exe

pause