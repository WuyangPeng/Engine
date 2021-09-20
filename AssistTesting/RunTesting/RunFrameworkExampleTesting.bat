@echo on 

start /d %AssistTestingWin32DebugLib% FrameworkExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% FrameworkExampleTesting.exe
start /d %AssistTestingX64DebugLib% FrameworkExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% FrameworkExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% FrameworkExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% FrameworkExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% FrameworkExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% FrameworkExampleTestingStatic.exe

pause