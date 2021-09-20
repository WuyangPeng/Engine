@echo on 

start /d %AssistTestingWin32DebugLib% MaterialEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% MaterialEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% MaterialEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% MaterialEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% MaterialEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% MaterialEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% MaterialEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% MaterialEditorAssistTestingStatic.exe

pause