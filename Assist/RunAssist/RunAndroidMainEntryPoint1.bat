@echo on 

start /d %AssistWin32DebugLib% AndroidMainEntryPoint1D.exe
start /d %AssistWin32ReleaseLib% AndroidMainEntryPoint1.exe
start /d %AssistX64DebugLib% AndroidMainEntryPoint1D.exe
start /d %AssistX64ReleaseLib% AndroidMainEntryPoint1.exe
start /d %AssistStaticWin32DebugLib% AndroidMainEntryPoint1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% AndroidMainEntryPoint1Static.exe
start /d %AssistStaticX64DebugLib% AndroidMainEntryPoint1StaticD.exe
start /d %AssistStaticX64ReleaseLib% AndroidMainEntryPoint1Static.exe

pause