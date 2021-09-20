@echo on 

start /d %AssistWin32DebugLib% WindowMessageLoop1D.exe
start /d %AssistWin32ReleaseLib% WindowMessageLoop1.exe
start /d %AssistX64DebugLib% WindowMessageLoop1D.exe
start /d %AssistX64ReleaseLib% WindowMessageLoop1.exe
start /d %AssistStaticWin32DebugLib% WindowMessageLoop1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WindowMessageLoop1Static.exe
start /d %AssistStaticX64DebugLib% WindowMessageLoop1StaticD.exe
start /d %AssistStaticX64ReleaseLib% WindowMessageLoop1Static.exe

pause