@echo on 

start /d %EngineTestingWin32DebugLib% SystemTestingD.exe
start /d %EngineTestingWin32ReleaseLib% SystemTesting.exe
start /d %EngineTestingX64DebugLib% SystemTestingD.exe
start /d %EngineTestingX64ReleaseLib% SystemTesting.exe
start /d %EngineTestingStaticWin32DebugLib% SystemTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% SystemTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% SystemTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% SystemTestingStatic.exe

pause