@echo on 

start /d %AssistWin32DebugLib% UserInterfaceEditorD.exe
start /d %AssistWin32ReleaseLib% UserInterfaceEditor.exe
start /d %AssistX64DebugLib% UserInterfaceEditorD.exe
start /d %AssistX64ReleaseLib% UserInterfaceEditor.exe
start /d %AssistStaticWin32DebugLib% UserInterfaceEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% UserInterfaceEditorStatic.exe
start /d %AssistStaticX64DebugLib% UserInterfaceEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% UserInterfaceEditorStatic.exe

pause