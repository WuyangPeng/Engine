@echo on 

start /d %AssistTestingWin32DebugLib% BookGameDesignTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGameDesignTesting.exe
start /d %AssistTestingX64DebugLib% BookGameDesignTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGameDesignTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGameDesignTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGameDesignTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGameDesignTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGameDesignTestingStatic.exe

pause