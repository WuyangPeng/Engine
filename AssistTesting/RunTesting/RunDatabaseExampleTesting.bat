@echo on 

start /d %AssistTestingWin32DebugLib% DatabaseExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% DatabaseExampleTesting.exe
start /d %AssistTestingX64DebugLib% DatabaseExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% DatabaseExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% DatabaseExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% DatabaseExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% DatabaseExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% DatabaseExampleTestingStatic.exe

pause