@echo on 

start /d %AssistTestingWin32DebugLib% BookCppTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookCppTesting.exe
start /d %AssistTestingX64DebugLib% BookCppTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookCppTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookCppTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookCppTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookCppTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookCppTestingStatic.exe

pause