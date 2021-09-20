@echo on 

start /d %AssistWin32DebugLib% MaterialEditorD.exe
start /d %AssistWin32ReleaseLib% MaterialEditor.exe
start /d %AssistX64DebugLib% MaterialEditorD.exe
start /d %AssistX64ReleaseLib% MaterialEditor.exe
start /d %AssistStaticWin32DebugLib% MaterialEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% MaterialEditorStatic.exe
start /d %AssistStaticX64DebugLib% MaterialEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% MaterialEditorStatic.exe

pause