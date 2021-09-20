@echo on 

start /d %AssistWin32DebugLib% WinMainEntryPoint3D.exe
start /d %AssistWin32ReleaseLib% WinMainEntryPoint3.exe
start /d %AssistX64DebugLib% WinMainEntryPoint3D.exe
start /d %AssistX64ReleaseLib% WinMainEntryPoint3.exe
start /d %AssistStaticWin32DebugLib% WinMainEntryPoint3StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WinMainEntryPoint3Static.exe
start /d %AssistStaticX64DebugLib% WinMainEntryPoint3StaticD.exe
start /d %AssistStaticX64ReleaseLib% WinMainEntryPoint3Static.exe

pause