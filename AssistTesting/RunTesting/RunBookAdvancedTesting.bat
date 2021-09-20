@echo on 

start /d %AssistTestingWin32DebugLib% BookAdvancedTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookAdvancedTesting.exe
start /d %AssistTestingX64DebugLib% BookAdvancedTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookAdvancedTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookAdvancedTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookAdvancedTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookAdvancedTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookAdvancedTestingStatic.exe

pause