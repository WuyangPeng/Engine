@echo on 

start /d %AssistTestingWin32DebugLib% ShaderEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ShaderEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% ShaderEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% ShaderEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ShaderEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ShaderEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ShaderEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ShaderEditorAssistTestingStatic.exe

pause