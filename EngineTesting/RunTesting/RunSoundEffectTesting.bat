@echo on 

start /d %EngineTestingWin32DebugLib% SoundEffectTestingD.exe
start /d %EngineTestingWin32ReleaseLib% SoundEffectTesting.exe
start /d %EngineTestingX64DebugLib% SoundEffectTestingD.exe
start /d %EngineTestingX64ReleaseLib% SoundEffectTesting.exe
start /d %EngineTestingStaticWin32DebugLib% SoundEffectTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% SoundEffectTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% SoundEffectTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% SoundEffectTestingStatic.exe

pause