@echo on 

start /d %AssistWin32DebugLib% AndroidMainFunctionHelper1D.exe
start /d %AssistWin32ReleaseLib% AndroidMainFunctionHelper1.exe
start /d %AssistX64DebugLib% AndroidMainFunctionHelper1D.exe
start /d %AssistX64ReleaseLib% AndroidMainFunctionHelper1.exe
start /d %AssistStaticWin32DebugLib% AndroidMainFunctionHelper1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% AndroidMainFunctionHelper1Static.exe
start /d %AssistStaticX64DebugLib% AndroidMainFunctionHelper1StaticD.exe
start /d %AssistStaticX64ReleaseLib% AndroidMainFunctionHelper1Static.exe

pause