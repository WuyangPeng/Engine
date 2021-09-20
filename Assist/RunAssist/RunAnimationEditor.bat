@echo on 

start /d %AssistWin32DebugLib% AnimationEditorD.exe
start /d %AssistWin32ReleaseLib% AnimationEditor.exe
start /d %AssistX64DebugLib% AnimationEditorD.exe
start /d %AssistX64ReleaseLib% AnimationEditor.exe
start /d %AssistStaticWin32DebugLib% AnimationEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% AnimationEditorStatic.exe
start /d %AssistStaticX64DebugLib% AnimationEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% AnimationEditorStatic.exe

pause