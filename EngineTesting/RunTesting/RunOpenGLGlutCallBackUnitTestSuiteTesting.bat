@echo on 

start /d %EngineTestingWin32DebugLib% OpenGLGlutCallBackUnitTestSuiteTestingD.exe
start /d %EngineTestingWin32ReleaseLib% OpenGLGlutCallBackUnitTestSuiteTesting.exe
start /d %EngineTestingX64DebugLib% OpenGLGlutCallBackUnitTestSuiteTestingD.exe
start /d %EngineTestingX64ReleaseLib% OpenGLGlutCallBackUnitTestSuiteTesting.exe
start /d %EngineTestingStaticWin32DebugLib% OpenGLGlutCallBackUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% OpenGLGlutCallBackUnitTestSuiteTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% OpenGLGlutCallBackUnitTestSuiteTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% OpenGLGlutCallBackUnitTestSuiteTestingStatic.exe

pause