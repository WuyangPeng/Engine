@echo on 

start /d %AssistTestingWin32DebugLib% BookSoundProgrammingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookSoundProgrammingTesting.exe
start /d %AssistTestingX64DebugLib% BookSoundProgrammingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookSoundProgrammingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookSoundProgrammingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookSoundProgrammingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookSoundProgrammingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookSoundProgrammingTestingStatic.exe

pause