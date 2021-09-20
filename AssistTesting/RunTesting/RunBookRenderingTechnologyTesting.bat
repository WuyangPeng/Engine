@echo on 

start /d %AssistTestingWin32DebugLib% BookRenderingTechnologyTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookRenderingTechnologyTesting.exe
start /d %AssistTestingX64DebugLib% BookRenderingTechnologyTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookRenderingTechnologyTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookRenderingTechnologyTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookRenderingTechnologyTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookRenderingTechnologyTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookRenderingTechnologyTestingStatic.exe

pause