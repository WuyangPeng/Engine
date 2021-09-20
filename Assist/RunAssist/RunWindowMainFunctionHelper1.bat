@echo on 

start /d %AssistWin32DebugLib% WindowMainFunctionHelper1D.exe
start /d %AssistWin32ReleaseLib% WindowMainFunctionHelper1.exe
start /d %AssistX64DebugLib% WindowMainFunctionHelper1D.exe
start /d %AssistX64ReleaseLib% WindowMainFunctionHelper1.exe
start /d %AssistStaticWin32DebugLib% WindowMainFunctionHelper1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% WindowMainFunctionHelper1Static.exe
start /d %AssistStaticX64DebugLib% WindowMainFunctionHelper1StaticD.exe
start /d %AssistStaticX64ReleaseLib% WindowMainFunctionHelper1Static.exe

pause