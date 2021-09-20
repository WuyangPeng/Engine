@echo on 

start /d %EngineTestingWin32DebugLib% OpenGLGlutMainFunctionHelperTestingD.exe
start /d %EngineTestingWin32ReleaseLib% OpenGLGlutMainFunctionHelperTesting.exe
start /d %EngineTestingX64DebugLib% OpenGLGlutMainFunctionHelperTestingD.exe
start /d %EngineTestingX64ReleaseLib% OpenGLGlutMainFunctionHelperTesting.exe
start /d %EngineTestingStaticWin32DebugLib% OpenGLGlutMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% OpenGLGlutMainFunctionHelperTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% OpenGLGlutMainFunctionHelperTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% OpenGLGlutMainFunctionHelperTestingStatic.exe

pause