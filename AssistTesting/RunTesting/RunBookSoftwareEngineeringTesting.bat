@echo on 

start /d %AssistTestingWin32DebugLib% BookSoftwareEngineeringTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookSoftwareEngineeringTesting.exe
start /d %AssistTestingX64DebugLib% BookSoftwareEngineeringTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookSoftwareEngineeringTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookSoftwareEngineeringTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookSoftwareEngineeringTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookSoftwareEngineeringTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookSoftwareEngineeringTestingStatic.exe

pause