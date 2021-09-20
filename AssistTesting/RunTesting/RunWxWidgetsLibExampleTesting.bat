@echo on 

start /d %AssistTestingWin32DebugLib% WxWidgetsLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% WxWidgetsLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% WxWidgetsLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% WxWidgetsLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% WxWidgetsLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% WxWidgetsLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% WxWidgetsLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% WxWidgetsLibExampleTestingStatic.exe

pause