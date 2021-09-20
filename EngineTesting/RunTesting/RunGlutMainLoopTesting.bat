@echo on 

start /d %EngineTestingWin32DebugLib% GlutMainLoopTestingD.exe
start /d %EngineTestingWin32ReleaseLib% GlutMainLoopTesting.exe
start /d %EngineTestingX64DebugLib% GlutMainLoopTestingD.exe
start /d %EngineTestingX64ReleaseLib% GlutMainLoopTesting.exe
start /d %EngineTestingStaticWin32DebugLib% GlutMainLoopTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% GlutMainLoopTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% GlutMainLoopTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% GlutMainLoopTestingStatic.exe

pause