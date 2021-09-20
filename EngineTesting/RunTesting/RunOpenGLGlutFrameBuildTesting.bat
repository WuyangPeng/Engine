@echo on 

start /d %EngineTestingWin32DebugLib% OpenGLGlutFrameBuildTestingD.exe
start /d %EngineTestingWin32ReleaseLib% OpenGLGlutFrameBuildTesting.exe
start /d %EngineTestingX64DebugLib% OpenGLGlutFrameBuildTestingD.exe
start /d %EngineTestingX64ReleaseLib% OpenGLGlutFrameBuildTesting.exe
start /d %EngineTestingStaticWin32DebugLib% OpenGLGlutFrameBuildTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% OpenGLGlutFrameBuildTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% OpenGLGlutFrameBuildTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% OpenGLGlutFrameBuildTestingStatic.exe

pause