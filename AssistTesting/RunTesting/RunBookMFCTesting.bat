@echo on 

start /d %AssistTestingWin32DebugLib% BookMFCTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookMFCTesting.exe
start /d %AssistTestingX64DebugLib% BookMFCTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookMFCTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookMFCTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookMFCTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookMFCTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookMFCTestingStatic.exe

pause