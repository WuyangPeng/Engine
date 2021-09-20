@echo on 

start /d %AssistTestingWin32DebugLib% UserInterfaceEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% UserInterfaceEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% UserInterfaceEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% UserInterfaceEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% UserInterfaceEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% UserInterfaceEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% UserInterfaceEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% UserInterfaceEditorAssistTestingStatic.exe

pause