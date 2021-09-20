@echo on 

start /d %AssistWin32DebugLib% SceneEditorD.exe
start /d %AssistWin32ReleaseLib% SceneEditor.exe
start /d %AssistX64DebugLib% SceneEditorD.exe
start /d %AssistX64ReleaseLib% SceneEditor.exe
start /d %AssistStaticWin32DebugLib% SceneEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% SceneEditorStatic.exe
start /d %AssistStaticX64DebugLib% SceneEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% SceneEditorStatic.exe

pause