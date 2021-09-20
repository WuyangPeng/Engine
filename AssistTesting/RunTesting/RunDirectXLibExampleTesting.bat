@echo on 

start /d %AssistTestingWin32DebugLib% DirectXLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% DirectXLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% DirectXLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% DirectXLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% DirectXLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% DirectXLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% DirectXLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% DirectXLibExampleTestingStatic.exe

pause