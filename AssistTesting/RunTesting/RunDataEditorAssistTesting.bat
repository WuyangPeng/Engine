@echo on 

start /d %AssistTestingWin32DebugLib% DataEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% DataEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% DataEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% DataEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% DataEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% DataEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% DataEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% DataEditorAssistTestingStatic.exe

pause