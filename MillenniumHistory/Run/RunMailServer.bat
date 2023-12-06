@echo on
 
start /d %MillenniumHistoryWin32DebugLib% MailServerD.exe
start /d %MillenniumHistoryWin32ReleaseLib% MailServer.exe
start /d %MillenniumHistoryX64DebugLib% MailServerD.exe
start /d %MillenniumHistoryX64ReleaseLib% MailServer.exe
start /d %MillenniumHistoryStaticWin32DebugLib% MailServerStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% MailServerStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% MailServerStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% MailServerStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% MailServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% MailServerStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% MailServerStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% MailServerStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% MailServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% MailServer.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% MailServerD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% MailServer.exe

pause