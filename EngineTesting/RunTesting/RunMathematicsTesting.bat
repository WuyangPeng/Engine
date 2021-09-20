@echo on 

start /d %EngineTestingWin32DebugLib% MathematicsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% MathematicsTesting.exe
start /d %EngineTestingX64DebugLib% MathematicsTestingD.exe
start /d %EngineTestingX64ReleaseLib% MathematicsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% MathematicsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% MathematicsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% MathematicsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% MathematicsTestingStatic.exe

pause