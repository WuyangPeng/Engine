@echo on
 
start /d %RiseOfHistoryTestingWin32DebugLib% MailServerTestingD.exe
start /d %RiseOfHistoryTestingWin32ReleaseLib% MailServerTesting.exe
start /d %RiseOfHistoryTestingX64DebugLib% MailServerTestingD.exe
start /d %RiseOfHistoryTestingX64ReleaseLib% MailServerTesting.exe
start /d %RiseOfHistoryTestingStaticWin32DebugLib% MailServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticWin32ReleaseLib% MailServerTestingStatic.exe
start /d %RiseOfHistoryTestingStaticX64DebugLib% MailServerTestingStaticD.exe
start /d %RiseOfHistoryTestingStaticX64ReleaseLib% MailServerTestingStatic.exe

start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib% MailServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MailServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib% MailServerTestingStaticD.exe
start /d %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MailServerTestingStatic.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib% MailServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MailServerTesting.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib% MailServerTestingD.exe
start /d %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MailServerTesting.exe

pause