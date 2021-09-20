@echo on 

start /d %EngineTestingWin32DebugLib% AndroidMainFunctionHelperTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AndroidMainFunctionHelperTesting.exe
start /d %EngineTestingX64DebugLib% AndroidMainFunctionHelperTestingD.exe
start /d %EngineTestingX64ReleaseLib% AndroidMainFunctionHelperTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AndroidMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AndroidMainFunctionHelperTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AndroidMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AndroidMainFunctionHelperTestingStatic.exe

pause