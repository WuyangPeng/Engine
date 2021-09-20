@echo on 

start /d %EngineTestingWin32DebugLib% DatabaseTestingD.exe
start /d %EngineTestingWin32ReleaseLib% DatabaseTesting.exe
start /d %EngineTestingX64DebugLib% DatabaseTestingD.exe
start /d %EngineTestingX64ReleaseLib% DatabaseTesting.exe
start /d %EngineTestingStaticWin32DebugLib% DatabaseTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% DatabaseTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% DatabaseTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% DatabaseTestingStatic.exe

pause