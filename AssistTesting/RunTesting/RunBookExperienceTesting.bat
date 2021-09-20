@echo on 

start /d %AssistTestingWin32DebugLib% BookExperienceTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookExperienceTesting.exe
start /d %AssistTestingX64DebugLib% BookExperienceTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookExperienceTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookExperienceTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookExperienceTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookExperienceTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookExperienceTestingStatic.exe

pause