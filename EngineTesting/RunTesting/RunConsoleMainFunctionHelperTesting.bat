@echo on 

start /d %EngineTestingWin32DebugLib% ConsoleMainFunctionHelperTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ConsoleMainFunctionHelperTesting.exe
start /d %EngineTestingX64DebugLib% ConsoleMainFunctionHelperTestingD.exe
start /d %EngineTestingX64ReleaseLib% ConsoleMainFunctionHelperTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ConsoleMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ConsoleMainFunctionHelperTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ConsoleMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ConsoleMainFunctionHelperTestingStatic.exe

pause