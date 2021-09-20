@echo on 

start /d %AssistWin32DebugLib% GlutMainEntryPoint2D.exe
start /d %AssistWin32ReleaseLib% GlutMainEntryPoint2.exe
start /d %AssistX64DebugLib% GlutMainEntryPoint2D.exe
start /d %AssistX64ReleaseLib% GlutMainEntryPoint2.exe
start /d %AssistStaticWin32DebugLib% GlutMainEntryPoint2StaticD.exe
start /d %AssistStaticWin32ReleaseLib% GlutMainEntryPoint2Static.exe
start /d %AssistStaticX64DebugLib% GlutMainEntryPoint2StaticD.exe
start /d %AssistStaticX64ReleaseLib% GlutMainEntryPoint2Static.exe

pause