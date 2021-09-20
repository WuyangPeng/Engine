@echo on 

start /d %EngineTestingWin32DebugLib% SystemOpenGLTestingD.exe
start /d %EngineTestingWin32ReleaseLib% SystemOpenGLTesting.exe
start /d %EngineTestingX64DebugLib% SystemOpenGLTestingD.exe
start /d %EngineTestingX64ReleaseLib% SystemOpenGLTesting.exe
start /d %EngineTestingStaticWin32DebugLib% SystemOpenGLTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% SystemOpenGLTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% SystemOpenGLTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% SystemOpenGLTestingStatic.exe

pause