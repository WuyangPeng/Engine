@echo on 

start /d %AssistTestingWin32DebugLib% EffectEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% EffectEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% EffectEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% EffectEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% EffectEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% EffectEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% EffectEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% EffectEditorAssistTestingStatic.exe

pause