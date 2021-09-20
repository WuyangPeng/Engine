@echo on 

start /d %AssistTestingWin32DebugLib% ACELibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ACELibExampleTesting.exe
start /d %AssistTestingX64DebugLib% ACELibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% ACELibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ACELibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ACELibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ACELibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ACELibExampleTestingStatic.exe

pause