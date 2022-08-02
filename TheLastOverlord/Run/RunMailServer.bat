@echo on
 
start /d %TheLastOverlordWin32DebugLib% MailServerD.exe
start /d %TheLastOverlordWin32ReleaseLib% MailServer.exe
start /d %TheLastOverlordX64DebugLib% MailServerD.exe
start /d %TheLastOverlordX64ReleaseLib% MailServer.exe
start /d %TheLastOverlordStaticWin32DebugLib% MailServerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% MailServerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% MailServerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% MailServerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% MailServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% MailServerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% MailServerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% MailServerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% MailServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% MailServer.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% MailServerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% MailServer.exe

pause