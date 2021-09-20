@echo on 

start /d %AssistTestingWin32DebugLib% BookPrimaryTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookPrimaryTesting.exe
start /d %AssistTestingX64DebugLib% BookPrimaryTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookPrimaryTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookPrimaryTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookPrimaryTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookPrimaryTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookPrimaryTestingStatic.exe

pause