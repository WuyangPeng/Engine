@echo on 

start /d %AssistWin32DebugLib% MacintoshMainFunctionHelper1D.exe
start /d %AssistWin32ReleaseLib% MacintoshMainFunctionHelper1.exe
start /d %AssistX64DebugLib% MacintoshMainFunctionHelper1D.exe
start /d %AssistX64ReleaseLib% MacintoshMainFunctionHelper1.exe
start /d %AssistStaticWin32DebugLib% MacintoshMainFunctionHelper1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% MacintoshMainFunctionHelper1Static.exe
start /d %AssistStaticX64DebugLib% MacintoshMainFunctionHelper1StaticD.exe
start /d %AssistStaticX64ReleaseLib% MacintoshMainFunctionHelper1Static.exe

pause