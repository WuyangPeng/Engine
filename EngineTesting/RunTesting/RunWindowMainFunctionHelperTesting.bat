@echo on 

start /d %EngineTestingWin32DebugLib% WindowMainFunctionHelperTestingD.exe
start /d %EngineTestingWin32ReleaseLib% WindowMainFunctionHelperTesting.exe
start /d %EngineTestingX64DebugLib% WindowMainFunctionHelperTestingD.exe
start /d %EngineTestingX64ReleaseLib% WindowMainFunctionHelperTesting.exe
start /d %EngineTestingStaticWin32DebugLib% WindowMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% WindowMainFunctionHelperTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% WindowMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% WindowMainFunctionHelperTestingStatic.exe

pause