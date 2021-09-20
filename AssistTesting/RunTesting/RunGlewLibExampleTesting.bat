@echo on 

start /d %AssistTestingWin32DebugLib% GlewLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% GlewLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% GlewLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% GlewLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% GlewLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% GlewLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% GlewLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% GlewLibExampleTestingStatic.exe

pause