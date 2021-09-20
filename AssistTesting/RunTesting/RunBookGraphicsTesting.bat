@echo on 

start /d %AssistTestingWin32DebugLib% BookGraphicsTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGraphicsTesting.exe
start /d %AssistTestingX64DebugLib% BookGraphicsTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGraphicsTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGraphicsTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGraphicsTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGraphicsTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGraphicsTestingStatic.exe

pause