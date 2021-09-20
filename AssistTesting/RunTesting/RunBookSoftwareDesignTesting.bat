@echo on 

start /d %AssistTestingWin32DebugLib% BookSoftwareDesignTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookSoftwareDesignTesting.exe
start /d %AssistTestingX64DebugLib% BookSoftwareDesignTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookSoftwareDesignTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookSoftwareDesignTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookSoftwareDesignTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookSoftwareDesignTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookSoftwareDesignTestingStatic.exe

pause