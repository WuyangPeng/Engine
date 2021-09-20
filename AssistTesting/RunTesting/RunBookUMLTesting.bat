@echo on 

start /d %AssistTestingWin32DebugLib% BookUMLTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookUMLTesting.exe
start /d %AssistTestingX64DebugLib% BookUMLTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookUMLTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookUMLTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookUMLTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookUMLTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookUMLTestingStatic.exe

pause