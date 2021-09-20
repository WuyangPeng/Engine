@echo on 

start /d %EngineTestingWin32DebugLib% CoreToolsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% CoreToolsTesting.exe
start /d %EngineTestingX64DebugLib% CoreToolsTestingD.exe
start /d %EngineTestingX64ReleaseLib% CoreToolsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% CoreToolsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% CoreToolsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% CoreToolsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% CoreToolsTestingStatic.exe

pause