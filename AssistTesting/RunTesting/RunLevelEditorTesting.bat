@echo on 

start /d %AssistTestingWin32DebugLib% LevelEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% LevelEditorTesting.exe
start /d %AssistTestingX64DebugLib% LevelEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% LevelEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% LevelEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% LevelEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% LevelEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% LevelEditorTestingStatic.exe

pause