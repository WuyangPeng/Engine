@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% OfflineServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% OfflineServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% OfflineServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% OfflineServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% OfflineServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% OfflineServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% OfflineServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% OfflineServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% OfflineServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% OfflineServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% OfflineServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% OfflineServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% OfflineServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% OfflineServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% OfflineServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% OfflineServerTesting.exe

pause