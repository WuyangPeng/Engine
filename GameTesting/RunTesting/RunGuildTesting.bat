@echo on
 
start /d %GameTestingWin32DebugLib% GuildTestingD.exe
start /d %GameTestingWin32ReleaseLib% GuildTesting.exe
start /d %GameTestingX64DebugLib% GuildTestingD.exe
start /d %GameTestingX64ReleaseLib% GuildTesting.exe
start /d %GameTestingStaticWin32DebugLib% GuildTestingStaticD.exe
start /d %GameTestingStaticWin32ReleaseLib% GuildTestingStatic.exe
start /d %GameTestingStaticX64DebugLib% GuildTestingStaticD.exe
start /d %GameTestingStaticX64ReleaseLib% GuildTestingStatic.exe

start /d %GameTestingEngineStaticGameDynamicWin32DebugLib% GuildTestingD.exe
start /d %GameTestingEngineStaticGameDynamicWin32ReleaseLib% GuildTesting.exe
start /d %GameTestingEngineStaticGameDynamicX64DebugLib% GuildTestingD.exe
start /d %GameTestingEngineStaticGameDynamicX64ReleaseLib% GuildTesting.exe
start /d %GameTestingEngineDynamicGameStaticWin32DebugLib% GuildTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticWin32ReleaseLib% GuildTestingStatic.exe
start /d %GameTestingEngineDynamicGameStaticX64DebugLib% GuildTestingStaticD.exe
start /d %GameTestingEngineDynamicGameStaticX64ReleaseLib% GuildTestingStatic.exe

pause