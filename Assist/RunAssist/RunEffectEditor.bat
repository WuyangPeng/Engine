@echo on 

start /d %AssistWin32DebugLib% EffectEditorD.exe
start /d %AssistWin32ReleaseLib% EffectEditor.exe
start /d %AssistX64DebugLib% EffectEditorD.exe
start /d %AssistX64ReleaseLib% EffectEditor.exe
start /d %AssistStaticWin32DebugLib% EffectEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% EffectEditorStatic.exe
start /d %AssistStaticX64DebugLib% EffectEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% EffectEditorStatic.exe

pause