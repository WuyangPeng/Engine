@echo on 

start /d %EngineTestingWin32DebugLib% FrameworkTestingD.exe
start /d %EngineTestingWin32ReleaseLib% FrameworkTesting.exe
start /d %EngineTestingX64DebugLib% FrameworkTestingD.exe
start /d %EngineTestingX64ReleaseLib% FrameworkTesting.exe
start /d %EngineTestingStaticWin32DebugLib% FrameworkTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% FrameworkTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% FrameworkTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% FrameworkTestingStatic.exe

pause