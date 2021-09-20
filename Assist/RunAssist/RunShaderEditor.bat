@echo on 

start /d %AssistWin32DebugLib% ShaderEditorD.exe
start /d %AssistWin32ReleaseLib% ShaderEditor.exe
start /d %AssistX64DebugLib% ShaderEditorD.exe
start /d %AssistX64ReleaseLib% ShaderEditor.exe
start /d %AssistStaticWin32DebugLib% ShaderEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ShaderEditorStatic.exe
start /d %AssistStaticX64DebugLib% ShaderEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% ShaderEditorStatic.exe

pause