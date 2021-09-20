@echo on 

start /d %AssistTestingWin32DebugLib% RenderingExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% RenderingExampleTesting.exe
start /d %AssistTestingX64DebugLib% RenderingExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% RenderingExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% RenderingExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% RenderingExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% RenderingExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% RenderingExampleTestingStatic.exe

pause