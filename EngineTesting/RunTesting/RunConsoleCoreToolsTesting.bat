@echo on 

start /d %EngineTestingWin32DebugLib% ConsoleCoreToolsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ConsoleCoreToolsTesting.exe
start /d %EngineTestingX64DebugLib% ConsoleCoreToolsTestingD.exe
start /d %EngineTestingX64ReleaseLib% ConsoleCoreToolsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ConsoleCoreToolsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ConsoleCoreToolsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ConsoleCoreToolsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ConsoleCoreToolsTestingStatic.exe

pause