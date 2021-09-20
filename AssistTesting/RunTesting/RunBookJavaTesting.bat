@echo on 

start /d %AssistTestingWin32DebugLib% BookJavaTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookJavaTesting.exe
start /d %AssistTestingX64DebugLib% BookJavaTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookJavaTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookJavaTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookJavaTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookJavaTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookJavaTestingStatic.exe

pause