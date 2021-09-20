@echo on 

start /d %AssistTestingWin32DebugLib% UserInterfaceEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% UserInterfaceEditorTesting.exe
start /d %AssistTestingX64DebugLib% UserInterfaceEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% UserInterfaceEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% UserInterfaceEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% UserInterfaceEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% UserInterfaceEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% UserInterfaceEditorTestingStatic.exe

pause