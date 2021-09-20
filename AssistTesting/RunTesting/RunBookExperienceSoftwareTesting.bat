@echo on 

start /d %AssistTestingWin32DebugLib% BookExperienceSoftwareTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookExperienceSoftwareTesting.exe
start /d %AssistTestingX64DebugLib% BookExperienceSoftwareTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookExperienceSoftwareTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookExperienceSoftwareTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookExperienceSoftwareTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookExperienceSoftwareTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookExperienceSoftwareTestingStatic.exe

pause