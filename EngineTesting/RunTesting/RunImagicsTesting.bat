@echo on 

start /d %EngineTestingWin32DebugLib% ImagicsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ImagicsTesting.exe
start /d %EngineTestingX64DebugLib% ImagicsTestingD.exe
start /d %EngineTestingX64ReleaseLib% ImagicsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ImagicsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ImagicsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ImagicsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ImagicsTestingStatic.exe

pause