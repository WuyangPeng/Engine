@echo on 

start /d %EngineTestingWin32DebugLib% AnimationTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AnimationTesting.exe
start /d %EngineTestingX64DebugLib% AnimationTestingD.exe
start /d %EngineTestingX64ReleaseLib% AnimationTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AnimationTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AnimationTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AnimationTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AnimationTestingStatic.exe

pause