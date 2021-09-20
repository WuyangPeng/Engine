@echo on 

start /d %AssistTestingWin32DebugLib% BookObjectOrientedTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookObjectOrientedTesting.exe
start /d %AssistTestingX64DebugLib% BookObjectOrientedTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookObjectOrientedTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookObjectOrientedTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookObjectOrientedTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookObjectOrientedTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookObjectOrientedTestingStatic.exe

pause