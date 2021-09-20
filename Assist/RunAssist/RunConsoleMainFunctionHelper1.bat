@echo on 

start /d %AssistWin32DebugLib% ConsoleMainFunctionHelper1D.exe
start /d %AssistWin32ReleaseLib% ConsoleMainFunctionHelper1.exe
start /d %AssistX64DebugLib% ConsoleMainFunctionHelper1D.exe
start /d %AssistX64ReleaseLib% ConsoleMainFunctionHelper1.exe
start /d %AssistStaticWin32DebugLib% ConsoleMainFunctionHelper1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% ConsoleMainFunctionHelper1Static.exe
start /d %AssistStaticX64DebugLib% ConsoleMainFunctionHelper1StaticD.exe
start /d %AssistStaticX64ReleaseLib% ConsoleMainFunctionHelper1Static.exe

pause