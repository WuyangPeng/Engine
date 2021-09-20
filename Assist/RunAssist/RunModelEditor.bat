@echo on 

start /d %AssistWin32DebugLib% ModelEditorD.exe
start /d %AssistWin32ReleaseLib% ModelEditor.exe
start /d %AssistX64DebugLib% ModelEditorD.exe
start /d %AssistX64ReleaseLib% ModelEditor.exe
start /d %AssistStaticWin32DebugLib% ModelEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ModelEditorStatic.exe
start /d %AssistStaticX64DebugLib% ModelEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% ModelEditorStatic.exe

pause