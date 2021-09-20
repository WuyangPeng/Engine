@echo on 

start /d %EngineTestingWin32DebugLib% PhysicsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% PhysicsTesting.exe
start /d %EngineTestingX64DebugLib% PhysicsTestingD.exe
start /d %EngineTestingX64ReleaseLib% PhysicsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% PhysicsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% PhysicsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% PhysicsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% PhysicsTestingStatic.exe

pause