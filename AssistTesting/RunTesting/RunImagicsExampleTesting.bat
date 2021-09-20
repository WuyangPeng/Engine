@echo on 

start /d %AssistTestingWin32DebugLib% ImagicsExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ImagicsExampleTesting.exe
start /d %AssistTestingX64DebugLib% ImagicsExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% ImagicsExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ImagicsExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ImagicsExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ImagicsExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ImagicsExampleTestingStatic.exe

pause