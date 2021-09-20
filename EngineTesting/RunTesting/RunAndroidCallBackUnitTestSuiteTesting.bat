@echo on 

start /d %EngineTestingWin32DebugLib% AndroidCallBackUnitTestSuiteTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AndroidCallBackUnitTestSuiteTesting.exe
start /d %EngineTestingX64DebugLib% AndroidCallBackUnitTestSuiteTestingD.exe
start /d %EngineTestingX64ReleaseLib% AndroidCallBackUnitTestSuiteTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AndroidCallBackUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AndroidCallBackUnitTestSuiteTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AndroidCallBackUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AndroidCallBackUnitTestSuiteTestingStatic.exe

pause