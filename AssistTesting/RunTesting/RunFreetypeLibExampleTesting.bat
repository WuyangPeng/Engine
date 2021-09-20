@echo on 

start /d %AssistTestingWin32DebugLib% FreetypeLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FreetypeLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% FreetypeLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% FreetypeLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FreetypeLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FreetypeLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FreetypeLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FreetypeLibExampleTestingStatic.exe

pause