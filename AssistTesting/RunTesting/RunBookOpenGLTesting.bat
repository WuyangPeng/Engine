@echo on 

start /d %AssistTestingWin32DebugLib% BookOpenGLTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookOpenGLTesting.exe
start /d %AssistTestingX64DebugLib% BookOpenGLTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookOpenGLTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookOpenGLTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookOpenGLTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookOpenGLTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookOpenGLTestingStatic.exe

pause