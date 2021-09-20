@echo on 

start /d %AssistTestingWin32DebugLib% BookGameProgrammingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGameProgrammingTesting.exe
start /d %AssistTestingX64DebugLib% BookGameProgrammingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGameProgrammingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGameProgrammingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGameProgrammingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGameProgrammingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGameProgrammingTestingStatic.exe

pause