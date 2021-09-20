@echo on 

start /d %AssistTestingWin32DebugLib% MathematicsExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% MathematicsExampleTesting.exe
start /d %AssistTestingX64DebugLib% MathematicsExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% MathematicsExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% MathematicsExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% MathematicsExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% MathematicsExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% MathematicsExampleTestingStatic.exe

pause