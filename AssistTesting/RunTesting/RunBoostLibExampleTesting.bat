@echo on 

start /d %AssistTestingWin32DebugLib% BoostLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BoostLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% BoostLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% BoostLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BoostLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BoostLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BoostLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BoostLibExampleTestingStatic.exe

pause