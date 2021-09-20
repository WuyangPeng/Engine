@echo on 

start /d %AssistTestingWin32DebugLib% BookPhysicsTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookPhysicsTesting.exe
start /d %AssistTestingX64DebugLib% BookPhysicsTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookPhysicsTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookPhysicsTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookPhysicsTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookPhysicsTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookPhysicsTestingStatic.exe

pause