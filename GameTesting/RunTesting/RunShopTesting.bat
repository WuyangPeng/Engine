@echo on
 
start /d %GameTestingWin32DebugLib% ShopTestingD.exe
start /d %GameTestingWin32ReleaseLib% ShopTesting.exe
start /d %GameTestingX64DebugLib% ShopTestingD.exe
start /d %GameTestingX64ReleaseLib% ShopTesting.exe
start /d %GameTestingStaticWin32DebugLib% ShopTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% ShopTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% ShopTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% ShopTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% ShopTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% ShopTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% ShopTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% ShopTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% ShopTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% ShopTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% ShopTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% ShopTestingStatic.exe

pause