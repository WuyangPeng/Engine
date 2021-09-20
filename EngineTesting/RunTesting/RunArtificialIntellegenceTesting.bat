@echo on 

start /d %EngineTestingWin32DebugLib% ArtificialIntellegenceTestingD.exe
start /d %EngineTestingWin32ReleaseLib% ArtificialIntellegenceTesting.exe
start /d %EngineTestingX64DebugLib% ArtificialIntellegenceTestingD.exe
start /d %EngineTestingX64ReleaseLib% ArtificialIntellegenceTesting.exe
start /d %EngineTestingStaticWin32DebugLib% ArtificialIntellegenceTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% ArtificialIntellegenceTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% ArtificialIntellegenceTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% ArtificialIntellegenceTestingStatic.exe

pause