@echo on 

start /d %AssistTestingWin32DebugLib% AssistToolsExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% AssistToolsExampleTesting.exe
start /d %AssistTestingX64DebugLib% AssistToolsExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% AssistToolsExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% AssistToolsExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% AssistToolsExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% AssistToolsExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% AssistToolsExampleTestingStatic.exe

pause