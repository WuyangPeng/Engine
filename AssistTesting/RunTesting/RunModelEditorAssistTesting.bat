@echo on 

start /d %AssistTestingWin32DebugLib% ModelEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ModelEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% ModelEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% ModelEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ModelEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ModelEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ModelEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ModelEditorAssistTestingStatic.exe

pause