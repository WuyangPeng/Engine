@echo on 

start /d %EngineTestingWin32DebugLib% MainFunctionHelperBaseTestingD.exe
start /d %EngineTestingWin32ReleaseLib% MainFunctionHelperBaseTesting.exe
start /d %EngineTestingX64DebugLib% MainFunctionHelperBaseTestingD.exe
start /d %EngineTestingX64ReleaseLib% MainFunctionHelperBaseTesting.exe
start /d %EngineTestingStaticWin32DebugLib% MainFunctionHelperBaseTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% MainFunctionHelperBaseTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% MainFunctionHelperBaseTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% MainFunctionHelperBaseTestingStatic.exe

pause