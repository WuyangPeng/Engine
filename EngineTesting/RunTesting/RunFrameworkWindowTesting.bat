@echo on 

start /d %EngineTestingWin32DebugLib% FrameworkWindowTestingD.exe
start /d %EngineTestingWin32ReleaseLib% FrameworkWindowTesting.exe
start /d %EngineTestingX64DebugLib% FrameworkWindowTestingD.exe
start /d %EngineTestingX64ReleaseLib% FrameworkWindowTesting.exe
start /d %EngineTestingStaticWin32DebugLib% FrameworkWindowTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% FrameworkWindowTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% FrameworkWindowTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% FrameworkWindowTestingStatic.exe

pause