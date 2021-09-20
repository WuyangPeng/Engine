@echo on 

start /d %AssistTestingWin32DebugLib% TerrainEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% TerrainEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% TerrainEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% TerrainEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% TerrainEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% TerrainEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% TerrainEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% TerrainEditorAssistTestingStatic.exe

pause