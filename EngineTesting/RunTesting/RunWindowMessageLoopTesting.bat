@echo on 

start /d %EngineTestingWin32DebugLib% WindowMessageLoopTestingD.exe
start /d %EngineTestingWin32ReleaseLib% WindowMessageLoopTesting.exe
start /d %EngineTestingX64DebugLib% WindowMessageLoopTestingD.exe
start /d %EngineTestingX64ReleaseLib% WindowMessageLoopTesting.exe
start /d %EngineTestingStaticWin32DebugLib% WindowMessageLoopTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% WindowMessageLoopTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% WindowMessageLoopTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% WindowMessageLoopTestingStatic.exe

pause