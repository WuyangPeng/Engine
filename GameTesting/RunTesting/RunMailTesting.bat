@echo on
 
start /d %GameTestingWin32DebugLib% MailTestingD.exe
start /d %GameTestingWin32ReleaseLib% MailTesting.exe
start /d %GameTestingX64DebugLib% MailTestingD.exe
start /d %GameTestingX64ReleaseLib% MailTesting.exe
start /d %GameTestingStaticWin32DebugLib% MailTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% MailTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% MailTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% MailTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% MailTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% MailTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% MailTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% MailTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% MailTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% MailTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% MailTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% MailTestingStatic.exe

pause