@echo on 

start /d %AssistWin32DebugLib% ConsoleMainFunctionHelperBase1D.exe -Type Console
start /d %AssistWin32ReleaseLib% ConsoleMainFunctionHelperBase1.exe -Type Console
start /d %AssistX64DebugLib% ConsoleMainFunctionHelperBase1D.exe -Type Console
start /d %AssistX64ReleaseLib% ConsoleMainFunctionHelperBase1.exe -Type Console
start /d %AssistStaticWin32DebugLib% ConsoleMainFunctionHelperBase1StaticD.exe -Type Console
start /d %AssistStaticWin32ReleaseLib% ConsoleMainFunctionHelperBase1Static.exe -Type Console
start /d %AssistStaticX64DebugLib% ConsoleMainFunctionHelperBase1StaticD.exe -Type Console
start /d %AssistStaticX64ReleaseLib% ConsoleMainFunctionHelperBase1Static.exe -Type Console

pause