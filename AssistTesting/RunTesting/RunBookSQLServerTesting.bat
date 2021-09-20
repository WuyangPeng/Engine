@echo on 

start /d %AssistTestingWin32DebugLib% BookSQLServerTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookSQLServerTesting.exe
start /d %AssistTestingX64DebugLib% BookSQLServerTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookSQLServerTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookSQLServerTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookSQLServerTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookSQLServerTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookSQLServerTestingStatic.exe

pause