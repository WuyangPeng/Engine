@echo on 

start /d %AssistWin32DebugLib% DataEditorD.exe
start /d %AssistWin32ReleaseLib% DataEditor.exe
start /d %AssistX64DebugLib% DataEditorD.exe
start /d %AssistX64ReleaseLib% DataEditor.exe
start /d %AssistStaticWin32DebugLib% DataEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% DataEditorStatic.exe
start /d %AssistStaticX64DebugLib% DataEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% DataEditorStatic.exe

pause