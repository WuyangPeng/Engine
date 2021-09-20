@echo on 

start /d %AssistTestingWin32DebugLib% MaterialEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% MaterialEditorTesting.exe
start /d %AssistTestingX64DebugLib% MaterialEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% MaterialEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% MaterialEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% MaterialEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% MaterialEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% MaterialEditorTestingStatic.exe

pause