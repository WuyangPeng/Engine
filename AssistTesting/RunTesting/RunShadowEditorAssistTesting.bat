@echo on 

start /d %AssistTestingWin32DebugLib% ShadowEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ShadowEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% ShadowEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% ShadowEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ShadowEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ShadowEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ShadowEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ShadowEditorAssistTestingStatic.exe

pause