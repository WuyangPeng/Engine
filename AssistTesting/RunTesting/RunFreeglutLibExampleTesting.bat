@echo on 

start /d %AssistTestingWin32DebugLib% FreeglutLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FreeglutLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% FreeglutLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% FreeglutLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FreeglutLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FreeglutLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FreeglutLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FreeglutLibExampleTestingStatic.exe

pause