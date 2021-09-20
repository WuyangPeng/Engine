@echo on 

start /d %AssistTestingWin32DebugLib% SkeletonEditorTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SkeletonEditorTesting.exe
start /d %AssistTestingX64DebugLib% SkeletonEditorTestingD.exe
start /d %AssistTestingX64ReleaseLib% SkeletonEditorTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SkeletonEditorTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SkeletonEditorTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SkeletonEditorTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SkeletonEditorTestingStatic.exe

pause