@echo on 

start /d %EngineTestingWin32DebugLib% UserInterfaceTestingD.exe
start /d %EngineTestingWin32ReleaseLib% UserInterfaceTesting.exe
start /d %EngineTestingX64DebugLib% UserInterfaceTestingD.exe
start /d %EngineTestingX64ReleaseLib% UserInterfaceTesting.exe
start /d %EngineTestingStaticWin32DebugLib% UserInterfaceTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% UserInterfaceTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% UserInterfaceTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% UserInterfaceTestingStatic.exe

pause