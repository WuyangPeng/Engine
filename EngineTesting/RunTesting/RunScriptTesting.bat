@echo on 

start /d %EngineTestingWin32DebugLib% ScriptTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ScriptTesting.exe
start /d %EngineTestingX64DebugLib% ScriptTestingD.exe
start /d %EngineTestingX64ReleaseLib% ScriptTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ScriptTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ScriptTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ScriptTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ScriptTestingStatic.exe

pause