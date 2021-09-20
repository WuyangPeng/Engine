@echo on 

start /d %AssistTestingWin32DebugLib% ScriptEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ScriptEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% ScriptEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% ScriptEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ScriptEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ScriptEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ScriptEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ScriptEditorAssistTestingStatic.exe

pause