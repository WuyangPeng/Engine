@echo on 

start /d %AssistTestingWin32DebugLib% SoundEffectExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% SoundEffectExampleTesting.exe
start /d %AssistTestingX64DebugLib% SoundEffectExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% SoundEffectExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% SoundEffectExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% SoundEffectExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% SoundEffectExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% SoundEffectExampleTestingStatic.exe

pause