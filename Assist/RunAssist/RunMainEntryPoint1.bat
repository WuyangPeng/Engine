@echo on 

start /d %AssistWin32DebugLib% MainEntryPoint1D.exe
start /d %AssistWin32ReleaseLib% MainEntryPoint1.exe
start /d %AssistX64DebugLib% MainEntryPoint1D.exe
start /d %AssistX64ReleaseLib% MainEntryPoint1.exe
start /d %AssistStaticWin32DebugLib% MainEntryPoint1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% MainEntryPoint1Static.exe
start /d %AssistStaticX64DebugLib% MainEntryPoint1StaticD.exe
start /d %AssistStaticX64ReleaseLib% MainEntryPoint1Static.exe

pause