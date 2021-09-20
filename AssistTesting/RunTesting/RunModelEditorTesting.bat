@echo on 

start /d %AssistTestingWin32DebugLib% ModelEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ModelEditorTesting.exe
start /d %AssistTestingX64DebugLib% ModelEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% ModelEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ModelEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ModelEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ModelEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ModelEditorTestingStatic.exe

pause