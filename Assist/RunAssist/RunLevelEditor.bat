@echo on 

start /d %AssistWin32DebugLib% LevelEditorD.exe
start /d %AssistWin32ReleaseLib% LevelEditor.exe
start /d %AssistX64DebugLib% LevelEditorD.exe
start /d %AssistX64ReleaseLib% LevelEditor.exe
start /d %AssistStaticWin32DebugLib% LevelEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% LevelEditorStatic.exe
start /d %AssistStaticX64DebugLib% LevelEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% LevelEditorStatic.exe

pause