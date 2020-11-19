@echo on

echo GameTestingInclude = %GameTestingInclude%
echo %cd%
setx GameTestingInclude "%cd%\..\Code" 

echo GameTestingWin32DebugLib = %GameTestingWin32DebugLib%
echo %cd%
setx GameTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo GameTestingWin32ReleaseLib = %GameTestingWin32ReleaseLib%
echo %cd%
setx GameTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo GameTestingX64DebugLib = %GameTestingX64DebugLib%
echo %cd%
setx GameTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo GameTestingX64ReleaseLib = %GameTestingX64ReleaseLib%
echo %cd%
setx GameTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo GameTestingStaticWin32DebugLib = %GameTestingStaticWin32DebugLib%
echo %cd%
setx GameTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo GameTestingStaticWin32ReleaseLib = %GameTestingStaticWin32ReleaseLib%
echo %cd%
setx GameTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo GameTestingStaticX64DebugLib = %GameTestingStaticX64DebugLib%
echo %cd%
setx GameTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo GameTestingStaticX64ReleaseLib = %GameTestingStaticX64ReleaseLib%
echo %cd%
setx GameTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo GameTestingEngineDynamicGameStaticWin32DebugLib = %GameTestingEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx GameTestingEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo GameTestingEngineDynamicGameStaticWin32ReleaseLib = %GameTestingEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx GameTestingEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo GameTestingEngineDynamicGameStaticX64DebugLib = %GameTestingEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx GameTestingEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo GameTestingEngineDynamicGameStaticX64ReleaseLib = %GameTestingEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx GameTestingEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo GameTestingEngineStaticGameDynamicWin32DebugLib = %GameTestingEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx GameTestingEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo GameTestingEngineStaticGameDynamicWin32ReleaseLib = %GameTestingEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx GameTestingEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo GameTestingEngineStaticGameDynamicX64DebugLib = %GameTestingEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx GameTestingEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo GameTestingEngineStaticGameDynamicX64ReleaseLib = %GameTestingEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx GameTestingEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause