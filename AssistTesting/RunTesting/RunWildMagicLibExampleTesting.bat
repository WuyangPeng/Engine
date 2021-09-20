@echo on 

start /d %AssistTestingWin32DebugLib% WildMagicLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% WildMagicLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% WildMagicLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% WildMagicLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% WildMagicLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% WildMagicLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% WildMagicLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% WildMagicLibExampleTestingStatic.exe

pause