@echo on 

start /d %AssistWin32DebugLib% GameTestingTemplateD.exe
start /d %AssistWin32ReleaseLib% GameTestingTemplate.exe
start /d %AssistX64DebugLib% GameTestingTemplateD.exe
start /d %AssistX64ReleaseLib% GameTestingTemplate.exe
start /d %AssistStaticWin32DebugLib% GameTestingTemplateStaticD.exe
start /d %AssistStaticWin32ReleaseLib% GameTestingTemplateStatic.exe
start /d %AssistStaticX64DebugLib% GameTestingTemplateStaticD.exe
start /d %AssistStaticX64ReleaseLib% GameTestingTemplateStatic.exe

pause