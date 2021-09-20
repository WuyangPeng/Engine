@echo on 

start /d %AssistTestingWin32DebugLib% BookModeTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookModeTesting.exe
start /d %AssistTestingX64DebugLib% BookModeTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookModeTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookModeTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookModeTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookModeTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookModeTestingStatic.exe

pause