@echo on 

start /d %AssistTestingWin32DebugLib% BookArtificialIntellegenceTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookArtificialIntellegenceTesting.exe
start /d %AssistTestingX64DebugLib% BookArtificialIntellegenceTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookArtificialIntellegenceTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookArtificialIntellegenceTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookArtificialIntellegenceTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookArtificialIntellegenceTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookArtificialIntellegenceTestingStatic.exe

pause