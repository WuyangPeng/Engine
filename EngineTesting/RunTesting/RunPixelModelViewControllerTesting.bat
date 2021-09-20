@echo on 

start /d %EngineTestingWin32DebugLib% PixelModelViewControllerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% PixelModelViewControllerTesting.exe
start /d %EngineTestingX64DebugLib% PixelModelViewControllerTestingD.exe
start /d %EngineTestingX64ReleaseLib% PixelModelViewControllerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% PixelModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% PixelModelViewControllerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% PixelModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% PixelModelViewControllerTestingStatic.exe

pause