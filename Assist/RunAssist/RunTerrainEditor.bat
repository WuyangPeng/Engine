@echo on 

start /d %AssistWin32DebugLib% TerrainEditorD.exe
start /d %AssistWin32ReleaseLib% TerrainEditor.exe
start /d %AssistX64DebugLib% TerrainEditorD.exe
start /d %AssistX64ReleaseLib% TerrainEditor.exe
start /d %AssistStaticWin32DebugLib% TerrainEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% TerrainEditorStatic.exe
start /d %AssistStaticX64DebugLib% TerrainEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% TerrainEditorStatic.exe

pause