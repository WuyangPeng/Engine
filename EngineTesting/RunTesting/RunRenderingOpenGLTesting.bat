@echo on 

start /d %EngineTestingWin32DebugLib% RenderingOpenGLTestingD.exe
start /d %EngineTestingWin32ReleaseLib% RenderingOpenGLTesting.exe
start /d %EngineTestingX64DebugLib% RenderingOpenGLTestingD.exe
start /d %EngineTestingX64ReleaseLib% RenderingOpenGLTesting.exe
start /d %EngineTestingStaticWin32DebugLib% RenderingOpenGLTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% RenderingOpenGLTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% RenderingOpenGLTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% RenderingOpenGLTestingStatic.exe

pause