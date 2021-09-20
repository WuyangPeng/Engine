@echo on 

start /d %AssistWin32DebugLib% ProcessTestD.exe
start /d %AssistWin32ReleaseLib% ProcessTest.exe
start /d %AssistX64DebugLib% ProcessTestD.exe
start /d %AssistX64ReleaseLib% ProcessTest.exe
start /d %AssistStaticWin32DebugLib% ProcessTestStaticD.exe
start /d %AssistStaticWin32ReleaseLib% ProcessTestStatic.exe
start /d %AssistStaticX64DebugLib% ProcessTestStaticD.exe
start /d %AssistStaticX64ReleaseLib% ProcessTestStatic.exe

pause