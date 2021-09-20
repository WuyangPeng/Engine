@echo on 

start /d %AssistTestingWin32DebugLib% OpensslLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% OpensslLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% OpensslLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% OpensslLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% OpensslLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% OpensslLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% OpensslLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% OpensslLibExampleTestingStatic.exe

pause