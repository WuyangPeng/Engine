@echo on 

start /d %AssistWin32DebugLib% OpenGLGlutMainFunctionHelper1D.exe
start /d %AssistWin32ReleaseLib% OpenGLGlutMainFunctionHelper1.exe
start /d %AssistX64DebugLib% OpenGLGlutMainFunctionHelper1D.exe
start /d %AssistX64ReleaseLib% OpenGLGlutMainFunctionHelper1.exe
start /d %AssistStaticWin32DebugLib% OpenGLGlutMainFunctionHelper1StaticD.exe
start /d %AssistStaticWin32ReleaseLib% OpenGLGlutMainFunctionHelper1Static.exe
start /d %AssistStaticX64DebugLib% OpenGLGlutMainFunctionHelper1StaticD.exe
start /d %AssistStaticX64ReleaseLib% OpenGLGlutMainFunctionHelper1Static.exe

pause