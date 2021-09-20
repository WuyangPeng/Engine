@echo on 

start /d %AssistTestingWin32DebugLib% BookGameDesignChildTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGameDesignChildTesting.exe
start /d %AssistTestingX64DebugLib% BookGameDesignChildTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGameDesignChildTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGameDesignChildTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGameDesignChildTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGameDesignChildTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGameDesignChildTestingStatic.exe

pause