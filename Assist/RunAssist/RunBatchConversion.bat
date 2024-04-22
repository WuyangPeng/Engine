@echo on 

start /d %AssistWin32DebugLib% BatchConversionD.exe
start /d %AssistWin32ReleaseLib% BatchConversion.exe
start /d %AssistX64DebugLib% BatchConversionD.exe
start /d %AssistX64ReleaseLib% BatchConversion.exe
start /d %AssistStaticWin32DebugLib% BatchConversionStaticD.exe
start /d %AssistStaticWin32ReleaseLib% BatchConversionStatic.exe
start /d %AssistStaticX64DebugLib% BatchConversionStaticD.exe
start /d %AssistStaticX64ReleaseLib% BatchConversionStatic.exe

pause