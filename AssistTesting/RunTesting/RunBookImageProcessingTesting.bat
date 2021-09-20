@echo on 

start /d %AssistTestingWin32DebugLib% BookImageProcessingTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookImageProcessingTesting.exe
start /d %AssistTestingX64DebugLib% BookImageProcessingTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookImageProcessingTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookImageProcessingTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookImageProcessingTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookImageProcessingTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookImageProcessingTestingStatic.exe

pause