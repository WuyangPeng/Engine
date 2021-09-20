@echo on 

start /d %AssistTestingWin32DebugLib% BookActionScript3TestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookActionScript3Testing.exe
start /d %AssistTestingX64DebugLib% BookActionScript3TestingD.exe
start /d %AssistTestingX64ReleaseLib% BookActionScript3Testing.exe
start /d %AssistTestingStaticWin32DebugLib% BookActionScript3TestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookActionScript3TestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookActionScript3TestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookActionScript3TestingStatic.exe

pause