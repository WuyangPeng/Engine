@echo on 

start /d %AssistWin32DebugLib% ShadowEditorD.exe
start /d %AssistWin32ReleaseLib% ShadowEditor.exe
start /d %AssistX64DebugLib% ShadowEditorD.exe
start /d %AssistX64ReleaseLib% ShadowEditor.exe
start /d %AssistStaticWin32DebugLib% ShadowEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ShadowEditorStatic.exe
start /d %AssistStaticX64DebugLib% ShadowEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% ShadowEditorStatic.exe

pause