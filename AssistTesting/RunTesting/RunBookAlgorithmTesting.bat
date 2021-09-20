@echo on 

start /d %AssistTestingWin32DebugLib% BookAlgorithmTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookAlgorithmTesting.exe
start /d %AssistTestingX64DebugLib% BookAlgorithmTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookAlgorithmTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookAlgorithmTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookAlgorithmTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookAlgorithmTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookAlgorithmTestingStatic.exe

pause