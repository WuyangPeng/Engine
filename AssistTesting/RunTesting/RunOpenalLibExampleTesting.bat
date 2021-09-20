@echo on 

start /d %AssistTestingWin32DebugLib% OpenalLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% OpenalLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% OpenalLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% OpenalLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% OpenalLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% OpenalLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% OpenalLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% OpenalLibExampleTestingStatic.exe

pause