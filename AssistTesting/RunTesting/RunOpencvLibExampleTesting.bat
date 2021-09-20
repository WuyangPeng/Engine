@echo on 

start /d %AssistTestingWin32DebugLib% OpencvLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% OpencvLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% OpencvLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% OpencvLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% OpencvLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% OpencvLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% OpencvLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% OpencvLibExampleTestingStatic.exe

pause