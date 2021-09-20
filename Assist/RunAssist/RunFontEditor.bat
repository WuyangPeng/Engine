@echo on 

start /d %AssistWin32DebugLib% FontEditorD.exe
start /d %AssistWin32ReleaseLib% FontEditor.exe
start /d %AssistX64DebugLib% FontEditorD.exe
start /d %AssistX64ReleaseLib% FontEditor.exe
start /d %AssistStaticWin32DebugLib% FontEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% FontEditorStatic.exe
start /d %AssistStaticX64DebugLib% FontEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% FontEditorStatic.exe

pause