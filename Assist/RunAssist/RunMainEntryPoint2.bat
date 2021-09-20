@echo on 

start /d %AssistWin32DebugLib% MainEntryPoint2D.exe
start /d %AssistWin32ReleaseLib% MainEntryPoint2.exe
start /d %AssistX64DebugLib% MainEntryPoint2D.exe
start /d %AssistX64ReleaseLib% MainEntryPoint2.exe
start /d %AssistStaticWin32DebugLib% MainEntryPoint2StaticD.exe
start /d %AssistStaticWin32ReleaseLib% MainEntryPoint2Static.exe
start /d %AssistStaticX64DebugLib% MainEntryPoint2StaticD.exe
start /d %AssistStaticX64ReleaseLib% MainEntryPoint2Static.exe

pause