@echo on 

start /d %AssistTestingWin32DebugLib% BookACETestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookACETesting.exe
start /d %AssistTestingX64DebugLib% BookACETestingD.exe
start /d %AssistTestingX64ReleaseLib% BookACETesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookACETestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookACETestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookACETestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookACETestingStatic.exe

pause