@echo on 

start /d %AssistTestingWin32DebugLib% ScriptExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ScriptExampleTesting.exe
start /d %AssistTestingX64DebugLib% ScriptExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% ScriptExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ScriptExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ScriptExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ScriptExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ScriptExampleTestingStatic.exe

pause