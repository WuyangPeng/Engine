@echo on 

start /d %AssistTestingWin32DebugLib% ShaderEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ShaderEditorTesting.exe
start /d %AssistTestingX64DebugLib% ShaderEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% ShaderEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ShaderEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ShaderEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ShaderEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ShaderEditorTestingStatic.exe

pause