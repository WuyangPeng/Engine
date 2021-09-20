@echo on 

start /d %AssistTestingWin32DebugLib% FreealutLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FreealutLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% FreealutLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% FreealutLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FreealutLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FreealutLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FreealutLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FreealutLibExampleTestingStatic.exe

pause