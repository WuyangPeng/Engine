@echo on 

start /d %AssistTestingWin32DebugLib% BookAgileDevelopmentTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookAgileDevelopmentTesting.exe
start /d %AssistTestingX64DebugLib% BookAgileDevelopmentTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookAgileDevelopmentTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookAgileDevelopmentTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookAgileDevelopmentTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookAgileDevelopmentTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookAgileDevelopmentTestingStatic.exe

pause