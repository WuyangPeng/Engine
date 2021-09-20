@echo on 

start /d %AssistTestingWin32DebugLib% PhysicsExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% PhysicsExampleTesting.exe
start /d %AssistTestingX64DebugLib% PhysicsExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% PhysicsExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% PhysicsExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% PhysicsExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% PhysicsExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% PhysicsExampleTestingStatic.exe

pause