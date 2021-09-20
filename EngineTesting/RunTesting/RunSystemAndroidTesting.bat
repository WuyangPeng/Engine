@echo on 

start /d %EngineTestingWin32DebugLib% SystemAndroidTestingD.exe
start /d %EngineTestingWin32ReleaseLib% SystemAndroidTesting.exe
start /d %EngineTestingX64DebugLib% SystemAndroidTestingD.exe
start /d %EngineTestingX64ReleaseLib% SystemAndroidTesting.exe
start /d %EngineTestingStaticWin32DebugLib% SystemAndroidTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% SystemAndroidTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% SystemAndroidTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% SystemAndroidTestingStatic.exe

pause