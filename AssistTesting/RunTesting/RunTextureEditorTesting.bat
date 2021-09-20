@echo on 

start /d %AssistTestingWin32DebugLib% TextureEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% TextureEditorTesting.exe
start /d %AssistTestingX64DebugLib% TextureEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% TextureEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% TextureEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% TextureEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% TextureEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% TextureEditorTestingStatic.exe

pause