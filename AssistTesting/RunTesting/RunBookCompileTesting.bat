@echo on 

start /d %AssistTestingWin32DebugLib% BookCompileTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookCompileTesting.exe
start /d %AssistTestingX64DebugLib% BookCompileTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookCompileTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookCompileTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookCompileTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookCompileTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookCompileTestingStatic.exe

pause