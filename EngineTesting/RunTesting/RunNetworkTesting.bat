@echo on 

start /d %EngineTestingWin32DebugLib% NetworkTestingD.exe
start /d %EngineTestingWin32ReleaseLib% NetworkTesting.exe
start /d %EngineTestingX64DebugLib% NetworkTestingD.exe
start /d %EngineTestingX64ReleaseLib% NetworkTesting.exe
start /d %EngineTestingStaticWin32DebugLib% NetworkTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% NetworkTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% NetworkTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% NetworkTestingStatic.exe

pause