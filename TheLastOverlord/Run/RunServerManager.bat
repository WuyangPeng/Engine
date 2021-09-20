@echo on
 
start /d %TheLastOverlordWin32DebugLib% ServerManagerD.exe
start /d %TheLastOverlordWin32ReleaseLib% ServerManager.exe
start /d %TheLastOverlordX64DebugLib% ServerManagerD.exe
start /d %TheLastOverlordX64ReleaseLib% ServerManager.exe
start /d %TheLastOverlordStaticWin32DebugLib% ServerManagerStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% ServerManagerStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% ServerManagerStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% ServerManagerStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% ServerManagerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% ServerManagerStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% ServerManagerStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% ServerManagerStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% ServerManagerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% ServerManager.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% ServerManagerD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% ServerManager.exe

pause