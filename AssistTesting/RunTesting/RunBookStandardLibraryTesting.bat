@echo on 

start /d %AssistTestingWin32DebugLib% BookStandardLibraryTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookStandardLibraryTesting.exe
start /d %AssistTestingX64DebugLib% BookStandardLibraryTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookStandardLibraryTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookStandardLibraryTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookStandardLibraryTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookStandardLibraryTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookStandardLibraryTestingStatic.exe

pause