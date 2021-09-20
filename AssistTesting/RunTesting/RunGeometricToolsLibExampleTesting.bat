GeometricToolsLibExampleTesting@echo on 

start /d %AssistTestingWin32DebugLib% GeometricToolsLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% GeometricToolsLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% GeometricToolsLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% GeometricToolsLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% GeometricToolsLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% GeometricToolsLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% GeometricToolsLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% GeometricToolsLibExampleTestingStatic.exe

pause