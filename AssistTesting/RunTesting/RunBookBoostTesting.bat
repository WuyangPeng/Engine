@echo on 

start /d %AssistTestingWin32DebugLib% BookBoostTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookBoostTesting.exe
start /d %AssistTestingX64DebugLib% BookBoostTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookBoostTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookBoostTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookBoostTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookBoostTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookBoostTestingStatic.exe

pause