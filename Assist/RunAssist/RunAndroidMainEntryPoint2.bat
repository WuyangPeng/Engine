@echo on 

start /d %AssistWin32DebugLib% AndroidMainEntryPoint2D.exe
start /d %AssistWin32ReleaseLib% AndroidMainEntryPoint2.exe
start /d %AssistX64DebugLib% AndroidMainEntryPoint2D.exe
start /d %AssistX64ReleaseLib% AndroidMainEntryPoint2.exe
start /d %AssistStaticWin32DebugLib% AndroidMainEntryPoint2StaticD.exe
start /d %AssistStaticWin32ReleaseLib% AndroidMainEntryPoint2Static.exe
start /d %AssistStaticX64DebugLib% AndroidMainEntryPoint2StaticD.exe
start /d %AssistStaticX64ReleaseLib% AndroidMainEntryPoint2Static.exe

pause