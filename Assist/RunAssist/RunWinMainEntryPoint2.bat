@echo on 

start /d %AssistWin32DebugLib% WinMainEntryPoint2D.exe
start /d %AssistWin32ReleaseLib% WinMainEntryPoint2.exe
start /d %AssistX64DebugLib% WinMainEntryPoint2D.exe
start /d %AssistX64ReleaseLib% WinMainEntryPoint2.exe
start /d %AssistStaticWin32DebugLib% WinMainEntryPoint2StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WinMainEntryPoint2Static.exe
start /d %AssistStaticX64DebugLib% WinMainEntryPoint2StaticD.exe
start /d %AssistStaticX64ReleaseLib% WinMainEntryPoint2Static.exe

pause