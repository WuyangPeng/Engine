@echo on 

start /d %AssistTestingWin32DebugLib% AnimationExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% AnimationExampleTesting.exe
start /d %AssistTestingX64DebugLib% AnimationExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% AnimationExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% AnimationExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% AnimationExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% AnimationExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% AnimationExampleTestingStatic.exe

pause