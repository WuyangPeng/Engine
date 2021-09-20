@echo on 

start /d %AssistWin32DebugLib% EditorD.exe
start /d %AssistWin32ReleaseLib% Editor.exe
start /d %AssistX64DebugLib% EditorD.exe
start /d %AssistX64ReleaseLib% Editor.exe
start /d %AssistStaticWin32DebugLib% EditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% EditorStatic.exe
start /d %AssistStaticX64DebugLib% EditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% EditorStatic.exe

pause