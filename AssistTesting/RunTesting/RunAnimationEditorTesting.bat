@echo on 

start /d %AssistTestingWin32DebugLib% AnimationEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% AnimationEditorTesting.exe
start /d %AssistTestingX64DebugLib% AnimationEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% AnimationEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% AnimationEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% AnimationEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% AnimationEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% AnimationEditorTestingStatic.exe

pause