@echo on 

start /d %AssistTestingWin32DebugLib% SceneEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SceneEditorTesting.exe
start /d %AssistTestingX64DebugLib% SceneEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% SceneEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SceneEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SceneEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SceneEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SceneEditorTestingStatic.exe

pause