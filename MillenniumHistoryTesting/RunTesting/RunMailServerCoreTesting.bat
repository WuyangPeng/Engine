@echo on
 
start /d %MillenniumHistoryTestingWin32DebugLib% MailServerCoreTestingD.exe
start /d %MillenniumHistoryTestingWin32ReleaseLib% MailServerCoreTesting.exe
start /d %MillenniumHistoryTestingX64DebugLib% MailServerCoreTestingD.exe
start /d %MillenniumHistoryTestingX64ReleaseLib% MailServerCoreTesting.exe
start /d %MillenniumHistoryTestingStaticWin32DebugLib% MailServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticWin32ReleaseLib% MailServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingStaticX64DebugLib% MailServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingStaticX64ReleaseLib% MailServerCoreTestingStatic.exe

start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib% MailServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib% MailServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib% MailServerCoreTestingStaticD.exe
start /d %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib% MailServerCoreTestingStatic.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib% MailServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib% MailServerCoreTesting.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib% MailServerCoreTestingD.exe
start /d %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib% MailServerCoreTesting.exe

pause