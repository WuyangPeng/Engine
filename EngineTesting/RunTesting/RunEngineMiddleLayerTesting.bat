@echo on 

start /d %EngineTestingWin32DebugLib% EngineMiddleLayerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% EngineMiddleLayerTesting.exe
start /d %EngineTestingX64DebugLib% EngineMiddleLayerTestingD.exe
start /d %EngineTestingX64ReleaseLib% EngineMiddleLayerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% EngineMiddleLayerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% EngineMiddleLayerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% EngineMiddleLayerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% EngineMiddleLayerTestingStatic.exe

pause