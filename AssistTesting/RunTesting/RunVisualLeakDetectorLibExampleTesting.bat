@echo on 

start /d %AssistTestingWin32DebugLib% VisualLeakDetectorLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% VisualLeakDetectorLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% VisualLeakDetectorLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% VisualLeakDetectorLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% VisualLeakDetectorLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% VisualLeakDetectorLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% VisualLeakDetectorLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% VisualLeakDetectorLibExampleTestingStatic.exe

pause