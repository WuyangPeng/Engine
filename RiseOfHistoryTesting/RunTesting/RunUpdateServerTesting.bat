@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% UpdateServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% UpdateServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% UpdateServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% UpdateServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% UpdateServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% UpdateServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% UpdateServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% UpdateServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% UpdateServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% UpdateServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% UpdateServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% UpdateServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% UpdateServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% UpdateServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% UpdateServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% UpdateServerTesting.exe

pause