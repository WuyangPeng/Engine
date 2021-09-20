@echo on 

start /d %AssistWin32DebugLib% ScriptEditorD.exe
start /d %AssistWin32ReleaseLib% ScriptEditor.exe
start /d %AssistX64DebugLib% ScriptEditorD.exe
start /d %AssistX64ReleaseLib% ScriptEditor.exe
start /d %AssistStaticWin32DebugLib% ScriptEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ScriptEditorStatic.exe
start /d %AssistStaticX64DebugLib% ScriptEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% ScriptEditorStatic.exe

pause