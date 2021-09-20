@echo on 

start /d %AssistTestingWin32DebugLib% BookOperatingSystemTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookOperatingSystemTesting.exe
start /d %AssistTestingX64DebugLib% BookOperatingSystemTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookOperatingSystemTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookOperatingSystemTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookOperatingSystemTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookOperatingSystemTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookOperatingSystemTestingStatic.exe

pause