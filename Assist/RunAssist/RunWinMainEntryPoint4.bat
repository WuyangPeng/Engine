@echo on 

start /d %AssistWin32DebugLib% WinMainEntryPoint4D.exe
start /d %AssistWin32ReleaseLib% WinMainEntryPoint4.exe
start /d %AssistX64DebugLib% WinMainEntryPoint4D.exe
start /d %AssistX64ReleaseLib% WinMainEntryPoint4.exe
start /d %AssistStaticWin32DebugLib% WinMainEntryPoint4StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WinMainEntryPoint4Static.exe
start /d %AssistStaticX64DebugLib% WinMainEntryPoint4StaticD.exe
start /d %AssistStaticX64ReleaseLib% WinMainEntryPoint4Static.exe

pause