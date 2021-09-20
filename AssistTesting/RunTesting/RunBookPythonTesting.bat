@echo on 

start /d %AssistTestingWin32DebugLib% BookPythonTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookPythonTesting.exe
start /d %AssistTestingX64DebugLib% BookPythonTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookPythonTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookPythonTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookPythonTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookPythonTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookPythonTestingStatic.exe

pause