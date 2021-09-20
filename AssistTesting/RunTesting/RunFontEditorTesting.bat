@echo on 

start /d %AssistTestingWin32DebugLib% FontEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FontEditorTesting.exe
start /d %AssistTestingX64DebugLib% FontEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% FontEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FontEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FontEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FontEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FontEditorTestingStatic.exe

pause