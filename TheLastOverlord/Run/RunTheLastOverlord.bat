@echo on
 
start /d %TheLastOverlordWin32DebugLib% TheLastOverlordD.exe
start /d %TheLastOverlordWin32ReleaseLib% TheLastOverlord.exe
start /d %TheLastOverlordX64DebugLib% TheLastOverlordD.exe
start /d %TheLastOverlordX64ReleaseLib% TheLastOverlord.exe
start /d %TheLastOverlordStaticWin32DebugLib% TheLastOverlordStaticD.exe
start /d %TheLastOverlordStaticWin32ReleaseLib% TheLastOverlordStatic.exe
start /d %TheLastOverlordStaticX64DebugLib% TheLastOverlordStaticD.exe
start /d %TheLastOverlordStaticX64ReleaseLib% TheLastOverlordStatic.exe

start /d %TheLastOverlordEngineStaticGameDynamicWin32DebugLib% TheLastOverlordStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib% TheLastOverlordStatic.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64DebugLib% TheLastOverlordStaticD.exe
start /d %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib% TheLastOverlordStatic.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32DebugLib% TheLastOverlordD.exe
start /d %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib% TheLastOverlord.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64DebugLib% TheLastOverlordD.exe
start /d %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib% TheLastOverlord.exe

pause