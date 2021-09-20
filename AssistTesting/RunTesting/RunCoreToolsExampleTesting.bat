@echo on 

start /d %AssistTestingWin32DebugLib% CoreToolsExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% CoreToolsExampleTesting.exe
start /d %AssistTestingX64DebugLib% CoreToolsExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% CoreToolsExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% CoreToolsExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% CoreToolsExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% CoreToolsExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% CoreToolsExampleTestingStatic.exe

pause