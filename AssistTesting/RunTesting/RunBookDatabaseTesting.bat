@echo on 

start /d %AssistTestingWin32DebugLib% BookDatabaseTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookDatabaseTesting.exe
start /d %AssistTestingX64DebugLib% BookDatabaseTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookDatabaseTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookDatabaseTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookDatabaseTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookDatabaseTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookDatabaseTestingStatic.exe

pause