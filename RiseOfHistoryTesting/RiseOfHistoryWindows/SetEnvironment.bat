@echo on

echo RiseOfHistoryTestingInclude = %RiseOfHistoryTestingInclude%
echo %cd%
setx RiseOfHistoryTestingInclude "%cd%\..\Code" 

echo RiseOfHistoryTestingEngineering = %RiseOfHistoryTestingEngineering%
echo %cd%
setx RiseOfHistoryTestingEngineering "%cd%\.." 

echo RiseOfHistoryTestingWin32DebugLib = %RiseOfHistoryTestingWin32DebugLib%
echo %cd%
setx RiseOfHistoryTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo RiseOfHistoryTestingWin32ReleaseLib = %RiseOfHistoryTestingWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo RiseOfHistoryTestingX64DebugLib = %RiseOfHistoryTestingX64DebugLib%
echo %cd%
setx RiseOfHistoryTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo RiseOfHistoryTestingX64ReleaseLib = %RiseOfHistoryTestingX64ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo RiseOfHistoryTestingStaticWin32DebugLib = %RiseOfHistoryTestingStaticWin32DebugLib%
echo %cd%
setx RiseOfHistoryTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo RiseOfHistoryTestingStaticWin32ReleaseLib = %RiseOfHistoryTestingStaticWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo RiseOfHistoryTestingStaticX64DebugLib = %RiseOfHistoryTestingStaticX64DebugLib%
echo %cd%
setx RiseOfHistoryTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo RiseOfHistoryTestingStaticX64ReleaseLib = %RiseOfHistoryTestingStaticX64ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib = %RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx RiseOfHistoryTestingEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib = %RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib = %RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx RiseOfHistoryTestingEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib = %RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib = %RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx RiseOfHistoryTestingEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib = %RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib = %RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx RiseOfHistoryTestingEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib = %RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx RiseOfHistoryTestingEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause