@echo on 

start /d %AssistTestingWin32DebugLib% TerrainEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% TerrainEditorTesting.exe
start /d %AssistTestingX64DebugLib% TerrainEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% TerrainEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% TerrainEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% TerrainEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% TerrainEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% TerrainEditorTestingStatic.exe

pause