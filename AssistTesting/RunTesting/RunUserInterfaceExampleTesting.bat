@echo on 

start /d %AssistTestingWin32DebugLib% UserInterfaceExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% UserInterfaceExampleTesting.exe
start /d %AssistTestingX64DebugLib% UserInterfaceExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% UserInterfaceExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% UserInterfaceExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% UserInterfaceExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% UserInterfaceExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% UserInterfaceExampleTestingStatic.exe

pause