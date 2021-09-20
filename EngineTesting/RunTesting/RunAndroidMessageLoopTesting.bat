@echo on 

start /d %EngineTestingWin32DebugLib% AndroidMessageLoopTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AndroidMessageLoopTesting.exe
start /d %EngineTestingX64DebugLib% AndroidMessageLoopTestingD.exe
start /d %EngineTestingX64ReleaseLib% AndroidMessageLoopTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AndroidMessageLoopTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AndroidMessageLoopTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AndroidMessageLoopTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AndroidMessageLoopTestingStatic.exe

pause