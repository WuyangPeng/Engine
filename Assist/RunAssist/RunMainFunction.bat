@echo on 

start /d %AssistWin32DebugLib% MainFunctionD.exe
start /d %AssistWin32ReleaseLib% MainFunction.exe
start /d %AssistX64DebugLib% MainFunctionD.exe
start /d %AssistX64ReleaseLib% MainFunction.exe
start /d %AssistStaticWin32DebugLib% MainFunctionStaticD.exe
start /d %AssistStaticWin32ReleaseLib% MainFunctionStatic.exe
start /d %AssistStaticX64DebugLib% MainFunctionStaticD.exe
start /d %AssistStaticX64ReleaseLib% MainFunctionStatic.exe

pause