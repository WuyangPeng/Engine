@echo on
 
start /d %EngineTestingWin32DebugLib% ThreadingCoreRenderEngineTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ThreadingCoreRenderEngineTesting.exe
start /d %EngineTestingX64DebugLib% ThreadingCoreRenderEngineTestingD.exe
start /d %EngineTestingX64ReleaseLib% ThreadingCoreRenderEngineTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ThreadingCoreRenderEngineTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ThreadingCoreRenderEngineTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ThreadingCoreRenderEngineTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ThreadingCoreRenderEngineTestingStatic.exe

pause