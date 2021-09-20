@echo on 

start /d %AssistTestingWin32DebugLib% BookWindowsAPITestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookWindowsAPITesting.exe
start /d %AssistTestingX64DebugLib% BookWindowsAPITestingD.exe
start /d %AssistTestingX64ReleaseLib% BookWindowsAPITesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookWindowsAPITestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookWindowsAPITestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookWindowsAPITestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookWindowsAPITestingStatic.exe

pause