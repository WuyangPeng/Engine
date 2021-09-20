@echo on 

start /d %AssistTestingWin32DebugLib% OgreLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% OgreLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% OgreLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% OgreLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% OgreLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% OgreLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% OgreLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% OgreLibExampleTestingStatic.exe

pause