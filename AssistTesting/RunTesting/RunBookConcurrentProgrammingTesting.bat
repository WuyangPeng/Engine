@echo on 

start /d %AssistTestingWin32DebugLib% BookConcurrentProgrammingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookConcurrentProgrammingTesting.exe
start /d %AssistTestingX64DebugLib% BookConcurrentProgrammingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookConcurrentProgrammingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookConcurrentProgrammingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookConcurrentProgrammingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookConcurrentProgrammingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookConcurrentProgrammingTestingStatic.exe

pause