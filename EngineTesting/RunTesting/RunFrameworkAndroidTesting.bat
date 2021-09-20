@echo on 

start /d %EngineTestingWin32DebugLib% FrameworkAndroidTestingD.exe
start /d %EngineTestingWin32ReleaseLib% FrameworkAndroidTesting.exe
start /d %EngineTestingX64DebugLib% FrameworkAndroidTestingD.exe
start /d %EngineTestingX64ReleaseLib% FrameworkAndroidTesting.exe
start /d %EngineTestingStaticWin32DebugLib% FrameworkAndroidTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% FrameworkAndroidTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% FrameworkAndroidTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% FrameworkAndroidTestingStatic.exe

pause