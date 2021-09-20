@echo on 

start /d %AssistTestingWin32DebugLib% IrrlichtLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% IrrlichtLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% IrrlichtLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% IrrlichtLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% IrrlichtLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% IrrlichtLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% IrrlichtLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% IrrlichtLibExampleTestingStatic.exe

pause