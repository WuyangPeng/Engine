@echo on 

start /d %AssistTestingWin32DebugLib% BookCodeTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookCodeTesting.exe
start /d %AssistTestingX64DebugLib% BookCodeTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookCodeTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookCodeTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookCodeTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookCodeTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookCodeTestingStatic.exe

pause