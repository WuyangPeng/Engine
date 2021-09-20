@echo on 

start /d %AssistWin32DebugLib% ExampleD.exe
start /d %AssistWin32ReleaseLib% Example.exe
start /d %AssistX64DebugLib% ExampleD.exe
start /d %AssistX64ReleaseLib% Example.exe
start /d %AssistStaticWin32DebugLib% ExampleStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ExampleStatic.exe
start /d %AssistStaticX64DebugLib% ExampleStaticD.exe
start /d %AssistStaticX64ReleaseLib% ExampleStatic.exe

pause