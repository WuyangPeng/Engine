@echo on 

start /d %AssistWin32DebugLib% CMainFunctionHelperD.exe
start /d %AssistWin32ReleaseLib% CMainFunctionHelper.exe
start /d %AssistX64DebugLib% CMainFunctionHelperD.exe
start /d %AssistX64ReleaseLib% CMainFunctionHelper.exe
start /d %AssistStaticWin32DebugLib% CMainFunctionHelperStaticD.exe
start /d %AssistStaticWin32ReleaseLib% CMainFunctionHelperStatic.exe
start /d %AssistStaticX64DebugLib% CMainFunctionHelperStaticD.exe
start /d %AssistStaticX64ReleaseLib% CMainFunctionHelperStatic.exe

pause