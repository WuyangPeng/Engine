@echo on 

start /d %AssistTestingWin32DebugLib% AnimationEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% AnimationEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% AnimationEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% AnimationEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% AnimationEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% AnimationEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% AnimationEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% AnimationEditorAssistTestingStatic.exe

pause