@echo on 

start /d %AssistTestingWin32DebugLib% BookTemplateTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookTemplateTesting.exe
start /d %AssistTestingX64DebugLib% BookTemplateTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookTemplateTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookTemplateTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookTemplateTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookTemplateTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookTemplateTestingStatic.exe

pause