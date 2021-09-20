@echo on 

start /d %AssistTestingWin32DebugLib% BookDebuggingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookDebuggingTesting.exe
start /d %AssistTestingX64DebugLib% BookDebuggingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookDebuggingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookDebuggingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookDebuggingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookDebuggingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookDebuggingTestingStatic.exe

pause