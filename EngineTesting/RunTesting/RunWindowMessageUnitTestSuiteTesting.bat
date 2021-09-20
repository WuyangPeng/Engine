@echo on 

start /d %EngineTestingWin32DebugLib% WindowMessageUnitTestSuiteTestingD.exe
start /d %EngineTestingWin32ReleaseLib% WindowMessageUnitTestSuiteTesting.exe
start /d %EngineTestingX64DebugLib% WindowMessageUnitTestSuiteTestingD.exe
start /d %EngineTestingX64ReleaseLib% WindowMessageUnitTestSuiteTesting.exe
start /d %EngineTestingStaticWin32DebugLib% WindowMessageUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% WindowMessageUnitTestSuiteTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% WindowMessageUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% WindowMessageUnitTestSuiteTestingStatic.exe

pause