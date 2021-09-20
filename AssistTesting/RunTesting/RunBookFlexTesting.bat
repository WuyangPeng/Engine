@echo on 

start /d %AssistTestingWin32DebugLib% BookFlexTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookFlexTesting.exe
start /d %AssistTestingX64DebugLib% BookFlexTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookFlexTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookFlexTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookFlexTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookFlexTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookFlexTestingStatic.exe

pause