@echo on 

start /d %AssistTestingWin32DebugLib% TextureEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% TextureEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% TextureEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% TextureEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% TextureEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% TextureEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% TextureEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% TextureEditorAssistTestingStatic.exe

pause