@echo on 

start /d %AssistWin32DebugLib% MainFunctionHelperBase1D.exe
start /d %AssistWin32ReleaseLib% MainFunctionHelperBase1.exe
start /d %AssistX64DebugLib% MainFunctionHelperBase1D.exe
start /d %AssistX64ReleaseLib% MainFunctionHelperBase1.exe
start /d %AssistStaticWin32DebugLib% MainFunctionHelperBase1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% MainFunctionHelperBase1Static.exe
start /d %AssistStaticX64DebugLib% MainFunctionHelperBase1StaticD.exe
start /d %AssistStaticX64ReleaseLib% MainFunctionHelperBase1Static.exe

pause