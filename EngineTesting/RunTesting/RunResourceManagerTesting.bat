@echo on 

start /d %EngineTestingWin32DebugLib% ResourceManagerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ResourceManagerTesting.exe
start /d %EngineTestingX64DebugLib% ResourceManagerTestingD.exe
start /d %EngineTestingX64ReleaseLib% ResourceManagerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ResourceManagerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ResourceManagerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ResourceManagerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ResourceManagerTestingStatic.exe

pause