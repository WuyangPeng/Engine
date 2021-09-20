@echo on 

start /d %AssistWin32DebugLib% TextureEditorD.exe
start /d %AssistWin32ReleaseLib% TextureEditor.exe
start /d %AssistX64DebugLib% TextureEditorD.exe
start /d %AssistX64ReleaseLib% TextureEditor.exe
start /d %AssistStaticWin32DebugLib% TextureEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% TextureEditorStatic.exe
start /d %AssistStaticX64DebugLib% TextureEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% TextureEditorStatic.exe

pause