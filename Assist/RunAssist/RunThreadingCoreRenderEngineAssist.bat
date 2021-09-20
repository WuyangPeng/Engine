@echo on 

start /d %AssistWin32DebugLib% ThreadingCoreRenderEngineAssistD.exe
start /d %AssistWin32ReleaseLib% ThreadingCoreRenderEngineAssist.exe
start /d %AssistX64DebugLib% ThreadingCoreRenderEngineAssistD.exe
start /d %AssistX64ReleaseLib% ThreadingCoreRenderEngineAssist.exe
start /d %AssistStaticWin32DebugLib% ThreadingCoreRenderEngineAssistStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ThreadingCoreRenderEngineAssistStatic.exe
start /d %AssistStaticX64DebugLib% ThreadingCoreRenderEngineAssistStaticD.exe
start /d %AssistStaticX64ReleaseLib% ThreadingCoreRenderEngineAssistStatic.exe

pause