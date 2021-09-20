@echo on 

start /d %AssistTestingWin32DebugLib% MysqlConnectorCppLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% MysqlConnectorCppLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% MysqlConnectorCppLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% MysqlConnectorCppLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% MysqlConnectorCppLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% MysqlConnectorCppLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% MysqlConnectorCppLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% MysqlConnectorCppLibExampleTestingStatic.exe

pause