@echo on 

start /d %EngineTestingWin32DebugLib% RenderingTestingD.exe
start /d %EngineTestingWin32ReleaseLib% RenderingTesting.exe
start /d %EngineTestingX64DebugLib% RenderingTestingD.exe
start /d %EngineTestingX64ReleaseLib% RenderingTesting.exe
start /d %EngineTestingStaticWin32DebugLib% RenderingTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% RenderingTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% RenderingTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% RenderingTestingStatic.exe

pause