@echo on 

start /d %EngineTestingWin32DebugLib% CameraModelViewControllerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% CameraModelViewControllerTesting.exe
start /d %EngineTestingX64DebugLib% CameraModelViewControllerTestingD.exe
start /d %EngineTestingX64ReleaseLib% CameraModelViewControllerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% CameraModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% CameraModelViewControllerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% CameraModelViewControllerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% CameraModelViewControllerTestingStatic.exe

pause