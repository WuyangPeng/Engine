@echo on 

start /d %AssistWin32DebugLib% SkeletonEditorD.exe
start /d %AssistWin32ReleaseLib% SkeletonEditor.exe
start /d %AssistX64DebugLib% SkeletonEditorD.exe
start /d %AssistX64ReleaseLib% SkeletonEditor.exe
start /d %AssistStaticWin32DebugLib% SkeletonEditorStaticD.exe
start /d %AssistStaticWin32ReleaseLib% SkeletonEditorStatic.exe
start /d %AssistStaticX64DebugLib% SkeletonEditorStaticD.exe
start /d %AssistStaticX64ReleaseLib% SkeletonEditorStatic.exe

pause