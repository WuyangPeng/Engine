@echo on 

start /d %AssistTestingWin32DebugLib% BookRegularExpressionTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookRegularExpressionTesting.exe
start /d %AssistTestingX64DebugLib% BookRegularExpressionTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookRegularExpressionTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookRegularExpressionTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookRegularExpressionTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookRegularExpressionTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookRegularExpressionTestingStatic.exe

pause