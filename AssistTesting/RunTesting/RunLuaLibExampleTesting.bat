@echo on 

start /d %AssistTestingWin32DebugLib% LuaLibExampleTestingD.exe
start /d %AssistTestingWin32ReleaseLib% LuaLibExampleTesting.exe
start /d %AssistTestingX64DebugLib% LuaLibExampleTestingD.exe
start /d %AssistTestingX64ReleaseLib% LuaLibExampleTesting.exe
start /d %AssistTestingStaticWin32DebugLib% LuaLibExampleTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% LuaLibExampleTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% LuaLibExampleTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% LuaLibExampleTestingStatic.exe

pause