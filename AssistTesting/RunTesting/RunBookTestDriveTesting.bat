@echo on 

start /d %AssistTestingWin32DebugLib% BookTestDriveTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookTestDriveTesting.exe
start /d %AssistTestingX64DebugLib% BookTestDriveTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookTestDriveTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookTestDriveTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookTestDriveTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookTestDriveTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookTestDriveTestingStatic.exe

pause