@echo on 

start /d %AssistTestingWin32DebugLib% ZlibLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ZlibLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% ZlibLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% ZlibLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ZlibLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ZlibLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ZlibLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ZlibLibExampleTestingStatic.exe

pause