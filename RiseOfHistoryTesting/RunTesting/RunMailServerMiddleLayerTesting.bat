@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% MailServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% MailServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% MailServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% MailServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% MailServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% MailServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% MailServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% MailServerMiddleLayerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% MailServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MailServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% MailServerMiddleLayerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MailServerMiddleLayerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% MailServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MailServerMiddleLayerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% MailServerMiddleLayerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MailServerMiddleLayerTesting.exe

pause