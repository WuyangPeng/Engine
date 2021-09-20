@echo on 

start /d %AssistTestingWin32DebugLib% MysqlLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% MysqlLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% MysqlLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% MysqlLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% MysqlLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% MysqlLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% MysqlLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% MysqlLibExampleTestingStatic.exe

pause