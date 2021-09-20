@echo on 

start /d %EngineTestingWin32DebugLib% FrameworkOpenGLGlutTestingD.exe
start /d %EngineTestingWin32ReleaseLib% FrameworkOpenGLGlutTesting.exe
start /d %EngineTestingX64DebugLib% FrameworkOpenGLGlutTestingD.exe
start /d %EngineTestingX64ReleaseLib% FrameworkOpenGLGlutTesting.exe
start /d %EngineTestingStaticWin32DebugLib% FrameworkOpenGLGlutTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% FrameworkOpenGLGlutTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% FrameworkOpenGLGlutTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% FrameworkOpenGLGlutTestingStatic.exe

pause