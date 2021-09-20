@echo on 

start /d %AssistTestingWin32DebugLib% BookSQLTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookSQLTesting.exe
start /d %AssistTestingX64DebugLib% BookSQLTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookSQLTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookSQLTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookSQLTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookSQLTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookSQLTestingStatic.exe

pause