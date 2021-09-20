@echo on 

start /d %AssistTestingWin32DebugLib% NetworkExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% NetworkExampleTesting.exe
start /d %AssistTestingX64DebugLib% NetworkExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% NetworkExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% NetworkExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% NetworkExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% NetworkExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% NetworkExampleTestingStatic.exe

pause