@echo on 

start /d %AssistTestingWin32DebugLib% DataEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% DataEditorTesting.exe
start /d %AssistTestingX64DebugLib% DataEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% DataEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% DataEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% DataEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% DataEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% DataEditorTestingStatic.exe

pause