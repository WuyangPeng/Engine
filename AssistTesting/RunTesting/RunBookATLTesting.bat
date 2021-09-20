@echo on 

start /d %AssistTestingWin32DebugLib% BookATLTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookATLTesting.exe
start /d %AssistTestingX64DebugLib% BookATLTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookATLTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookATLTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookATLTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookATLTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookATLTestingStatic.exe

pause