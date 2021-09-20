@echo on 

start /d %EngineTestingWin32DebugLib% ConsoleSystemTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ConsoleSystemTesting.exe
start /d %EngineTestingX64DebugLib% ConsoleSystemTestingD.exe
start /d %EngineTestingX64ReleaseLib% ConsoleSystemTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ConsoleSystemTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ConsoleSystemTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ConsoleSystemTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ConsoleSystemTestingStatic.exe

pause