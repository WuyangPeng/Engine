@echo on 

start /d %AssistWin32DebugLib% GameTemplateD.exe
start /d %AssistWin32ReleaseLib% GameTemplate.exe
start /d %AssistX64DebugLib% GameTemplateD.exe
start /d %AssistX64ReleaseLib% GameTemplate.exe
start /d %AssistStaticWin32DebugLib% GameTemplateStaticD.exe
start /d %AssistStaticWin32ReleaseLib% GameTemplateStatic.exe
start /d %AssistStaticX64DebugLib% GameTemplateStaticD.exe
start /d %AssistStaticX64ReleaseLib% GameTemplateStatic.exe

pause