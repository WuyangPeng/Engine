@echo on 

start /d %AssistTestingWin32DebugLib% SceneEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SceneEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% SceneEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% SceneEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SceneEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SceneEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SceneEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SceneEditorAssistTestingStatic.exe

pause