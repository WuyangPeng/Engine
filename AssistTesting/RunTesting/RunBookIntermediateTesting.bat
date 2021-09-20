@echo on 

start /d %AssistTestingWin32DebugLib% BookIntermediateTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookIntermediateTesting.exe
start /d %AssistTestingX64DebugLib% BookIntermediateTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookIntermediateTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookIntermediateTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookIntermediateTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookIntermediateTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookIntermediateTestingStatic.exe

pause