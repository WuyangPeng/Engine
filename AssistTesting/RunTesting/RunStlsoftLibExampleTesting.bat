@echo on 

start /d %AssistTestingWin32DebugLib% StlsoftLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% StlsoftLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% StlsoftLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% StlsoftLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% StlsoftLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% StlsoftLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% StlsoftLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% StlsoftLibExampleTestingStatic.exe

pause