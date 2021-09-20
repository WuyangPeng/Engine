@echo on 

start /d %AssistWin32DebugLib% GlutMainEntryPoint1D.exe
start /d %AssistWin32ReleaseLib% GlutMainEntryPoint1.exe
start /d %AssistX64DebugLib% GlutMainEntryPoint1D.exe
start /d %AssistX64ReleaseLib% GlutMainEntryPoint1.exe
start /d %AssistStaticWin32DebugLib% GlutMainEntryPoint1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% GlutMainEntryPoint1Static.exe
start /d %AssistStaticX64DebugLib% GlutMainEntryPoint1StaticD.exe
start /d %AssistStaticX64ReleaseLib% GlutMainEntryPoint1Static.exe

pause