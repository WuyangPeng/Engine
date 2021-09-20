@echo on 

start /d %AssistTestingWin32DebugLib% FontEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FontEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% FontEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% FontEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FontEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FontEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FontEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FontEditorAssistTestingStatic.exe

pause