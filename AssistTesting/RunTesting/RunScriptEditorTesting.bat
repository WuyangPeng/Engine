@echo on 

start /d %AssistTestingWin32DebugLib% ScriptEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ScriptEditorTesting.exe
start /d %AssistTestingX64DebugLib% ScriptEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% ScriptEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ScriptEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ScriptEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ScriptEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ScriptEditorTestingStatic.exe

pause