@echo on 

start /d %AssistTestingWin32DebugLib% SystemExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SystemExampleTesting.exe
start /d %AssistTestingX64DebugLib% SystemExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% SystemExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SystemExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SystemExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SystemExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SystemExampleTestingStatic.exe

pause