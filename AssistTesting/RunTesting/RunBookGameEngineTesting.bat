@echo on 

start /d %AssistTestingWin32DebugLib% BookGameEngineTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGameEngineTesting.exe
start /d %AssistTestingX64DebugLib% BookGameEngineTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGameEngineTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGameEngineTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGameEngineTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGameEngineTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGameEngineTestingStatic.exe

pause