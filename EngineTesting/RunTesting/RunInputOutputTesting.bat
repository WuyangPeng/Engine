@echo on 

start /d %EngineTestingWin32DebugLib% InputOutputTestingD.exe
start /d %EngineTestingWin32ReleaseLib% InputOutputTesting.exe
start /d %EngineTestingX64DebugLib% InputOutputTestingD.exe
start /d %EngineTestingX64ReleaseLib% InputOutputTesting.exe
start /d %EngineTestingStaticWin32DebugLib% InputOutputTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% InputOutputTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% InputOutputTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% InputOutputTestingStatic.exe

pause