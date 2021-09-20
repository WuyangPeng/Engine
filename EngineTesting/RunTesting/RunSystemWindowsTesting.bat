@echo on 

start /d %EngineTestingWin32DebugLib% SystemWindowsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% SystemWindowsTesting.exe
start /d %EngineTestingX64DebugLib% SystemWindowsTestingD.exe
start /d %EngineTestingX64ReleaseLib% SystemWindowsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% SystemWindowsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% SystemWindowsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% SystemWindowsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% SystemWindowsTestingStatic.exe

pause