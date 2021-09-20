@echo on 

start /d %AssistTestingWin32DebugLib% BookNetworkProgrammingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookNetworkProgrammingTesting.exe
start /d %AssistTestingX64DebugLib% BookNetworkProgrammingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookNetworkProgrammingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookNetworkProgrammingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookNetworkProgrammingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookNetworkProgrammingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookNetworkProgrammingTestingStatic.exe

pause