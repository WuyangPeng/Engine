@echo on 

start /d %AssistTestingWin32DebugLib% PerlLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% PerlLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% PerlLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% PerlLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% PerlLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% PerlLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% PerlLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% PerlLibExampleTestingStatic.exe

pause