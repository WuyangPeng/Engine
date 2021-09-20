@echo on 

start /d %EngineTestingWin32DebugLib% WindowsAPIFrameTestingD.exe
start /d %EngineTestingWin32ReleaseLib% WindowsAPIFrameTesting.exe
start /d %EngineTestingX64DebugLib% WindowsAPIFrameTestingD.exe
start /d %EngineTestingX64ReleaseLib% WindowsAPIFrameTesting.exe
start /d %EngineTestingStaticWin32DebugLib% WindowsAPIFrameTestingStaticD.exe
start /d %EngineTestingStaticWin32ReleaseLib% WindowsAPIFrameTestingStatic.exe
start /d %EngineTestingStaticX64DebugLib% WindowsAPIFrameTestingStaticD.exe
start /d %EngineTestingStaticX64ReleaseLib% WindowsAPIFrameTestingStatic.exe

pause