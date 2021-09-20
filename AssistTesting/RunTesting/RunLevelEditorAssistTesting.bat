@echo on 

start /d %AssistTestingWin32DebugLib% LevelEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% LevelEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% LevelEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% LevelEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% LevelEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% LevelEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% LevelEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% LevelEditorAssistTestingStatic.exe

pause