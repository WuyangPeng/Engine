@echo on 

start /d %EngineTestingWin32DebugLib% AssistToolsTestingD.exe
start /d %EngineTestingWin32ReleaseLib% AssistToolsTesting.exe
start /d %EngineTestingX64DebugLib% AssistToolsTestingD.exe
start /d %EngineTestingX64ReleaseLib% AssistToolsTesting.exe
start /d %EngineTestingStaticWin32DebugLib% AssistToolsTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% AssistToolsTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% AssistToolsTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% AssistToolsTestingStatic.exe

pause