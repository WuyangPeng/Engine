@echo on 

start /d %AssistTestingWin32DebugLib% ResourceManagerExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% ResourceManagerExampleTesting.exe
start /d %AssistTestingX64DebugLib% ResourceManagerExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% ResourceManagerExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% ResourceManagerExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% ResourceManagerExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% ResourceManagerExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% ResourceManagerExampleTestingStatic.exe

pause