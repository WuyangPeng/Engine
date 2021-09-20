@echo on 

start /d %AssistTestingWin32DebugLib% SkeletonEditorAssistTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SkeletonEditorAssistTesting.exe
start /d %AssistTestingX64DebugLib% SkeletonEditorAssistTestingD.exe
start /d %AssistTestingX64ReleaseLib% SkeletonEditorAssistTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SkeletonEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SkeletonEditorAssistTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SkeletonEditorAssistTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SkeletonEditorAssistTestingStatic.exe

pause