@echo on
 
start /d %RiseOfHistoryWin32DebugLib% MailServerD.exe
start /d %RiseOfHistoryWin32ReleaseLib% MailServer.exe
start /d %RiseOfHistoryX64DebugLib% MailServerD.exe
start /d %RiseOfHistoryX64ReleaseLib% MailServer.exe
start /d %RiseOfHistoryStaticWin32DebugLib% MailServerStaticD.exe
start /d %RiseOfHistoryStaticWin32ReleaseLib% MailServerStatic.exe
start /d %RiseOfHistoryStaticX64DebugLib% MailServerStaticD.exe
start /d %RiseOfHistoryStaticX64ReleaseLib% MailServerStatic.exe

start /d %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib% MailServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib% MailServerStatic.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64DebugLib% MailServerStaticD.exe
start /d %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib% MailServerStatic.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib% MailServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib% MailServer.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64DebugLib% MailServerD.exe
start /d %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib% MailServer.exe

pause