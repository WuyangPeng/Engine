@echo on 

start /d %AssistWin32DebugLib% WinMainEntryPoint1D.exe
start /d %AssistWin32ReleaseLib% WinMainEntryPoint1.exe
start /d %AssistX64DebugLib% WinMainEntryPoint1D.exe
start /d %AssistX64ReleaseLib% WinMainEntryPoint1.exe
start /d %AssistStaticWin32DebugLib% WinMainEntryPoint1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WinMainEntryPoint1Static.exe
start /d %AssistStaticX64DebugLib% WinMainEntryPoint1StaticD.exe
start /d %AssistStaticX64ReleaseLib% WinMainEntryPoint1Static.exe

pause