@echo on 

start /d %EngineTestingWin32DebugLib% AndroidFrameBuildTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AndroidFrameBuildTesting.exe
start /d %EngineTestingX64DebugLib% AndroidFrameBuildTestingD.exe
start /d %EngineTestingX64ReleaseLib% AndroidFrameBuildTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AndroidFrameBuildTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AndroidFrameBuildTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AndroidFrameBuildTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AndroidFrameBuildTestingStatic.exe

pause