@echo on 

start /d %AssistTestingWin32DebugLib% BookGeometryTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookGeometryTesting.exe
start /d %AssistTestingX64DebugLib% BookGeometryTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookGeometryTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookGeometryTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookGeometryTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookGeometryTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookGeometryTestingStatic.exe

pause