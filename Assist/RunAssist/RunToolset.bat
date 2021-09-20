@echo on 

start /d %AssistWin32DebugLib% ToolsetD.exe
start /d %AssistWin32ReleaseLib% Toolset.exe
start /d %AssistX64DebugLib% ToolsetD.exe
start /d %AssistX64ReleaseLib% Toolset.exe
start /d %AssistStaticWin32DebugLib% ToolsetStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ToolsetStatic.exe
start /d %AssistStaticX64DebugLib% ToolsetStaticD.exe
start /d %AssistStaticX64ReleaseLib% ToolsetStatic.exe

pause