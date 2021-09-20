@echo on 

start /d %AssistTestingWin32DebugLib% ShadowEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ShadowEditorTesting.exe
start /d %AssistTestingX64DebugLib% ShadowEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% ShadowEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ShadowEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ShadowEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ShadowEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ShadowEditorTestingStatic.exe

pause