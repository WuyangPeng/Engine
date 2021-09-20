@echo on 

start /d %EngineTestingWin32DebugLib% DefaultEngineMiddleLayerTestingD.exe
start /d %EngineTestingWin32ReleaseLib% DefaultEngineMiddleLayerTesting.exe
start /d %EngineTestingX64DebugLib% DefaultEngineMiddleLayerTestingD.exe
start /d %EngineTestingX64ReleaseLib% DefaultEngineMiddleLayerTesting.exe
start /d %EngineTestingStaticWin32DebugLib% DefaultEngineMiddleLayerTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% DefaultEngineMiddleLayerTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% DefaultEngineMiddleLayerTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% DefaultEngineMiddleLayerTestingStatic.exe

pause