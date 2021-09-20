@echo on 

start /d %AssistTestingWin32DebugLib% EffectEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% EffectEditorTesting.exe
start /d %AssistTestingX64DebugLib% EffectEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% EffectEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% EffectEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% EffectEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% EffectEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% EffectEditorTestingStatic.exe

pause