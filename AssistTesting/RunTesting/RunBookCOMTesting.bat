@echo on 

start /d %AssistTestingWin32DebugLib% BookCOMTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookCOMTesting.exe
start /d %AssistTestingX64DebugLib% BookCOMTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookCOMTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookCOMTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookCOMTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookCOMTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookCOMTestingStatic.exe

pause