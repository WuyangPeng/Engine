@echo on 

start /d %EngineTestingWin32DebugLib% ModelViewControllerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ModelViewControllerTesting.exe
start /d %EngineTestingX64DebugLib% ModelViewControllerTestingD.exe
start /d %EngineTestingX64ReleaseLib% ModelViewControllerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ModelViewControllerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ModelViewControllerTestingStatic.exe

pause