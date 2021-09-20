@echo on 

start /d %AssistTestingWin32DebugLib% InputOutputExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% InputOutputExampleTesting.exe
start /d %AssistTestingX64DebugLib% InputOutputExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% InputOutputExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% InputOutputExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% InputOutputExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% InputOutputExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% InputOutputExampleTestingStatic.exe

pause