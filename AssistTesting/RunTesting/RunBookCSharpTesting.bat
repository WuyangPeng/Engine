@echo on 

start /d %AssistTestingWin32DebugLib% BookCSharpTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookCSharpTesting.exe
start /d %AssistTestingX64DebugLib% BookCSharpTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookCSharpTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookCSharpTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookCSharpTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookCSharpTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookCSharpTestingStatic.exe

pause