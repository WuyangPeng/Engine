@echo on

echo RiseOfHistoryInclude = %RiseOfHistoryInclude%
echo %cd%
setx RiseOfHistoryInclude "%cd%\..\Code" 

echo RiseOfHistoryEngineering = %RiseOfHistoryEngineering%
echo %cd%
setx RiseOfHistoryEngineering "%cd%\.." 

echo RiseOfHistoryWin32DebugLib = %RiseOfHistoryWin32DebugLib%
echo %cd%
setx RiseOfHistoryWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo RiseOfHistoryWin32ReleaseLib = %RiseOfHistoryWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo RiseOfHistoryX64DebugLib = %RiseOfHistoryX64DebugLib%
echo %cd%
setx RiseOfHistoryX64DebugLib "%cd%\..\x64\DebugWindows" 

echo RiseOfHistoryX64ReleaseLib = %RiseOfHistoryX64ReleaseLib%
echo %cd%
setx RiseOfHistoryX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo RiseOfHistoryStaticWin32DebugLib = %RiseOfHistoryStaticWin32DebugLib%
echo %cd%
setx RiseOfHistoryStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo RiseOfHistoryStaticWin32ReleaseLib = %RiseOfHistoryStaticWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo RiseOfHistoryStaticX64DebugLib = %RiseOfHistoryStaticX64DebugLib%
echo %cd%
setx RiseOfHistoryStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo RiseOfHistoryStaticX64ReleaseLib = %RiseOfHistoryStaticX64ReleaseLib%
echo %cd%
setx RiseOfHistoryStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo RiseOfHistoryEngineDynamicGameStaticWin32DebugLib = %RiseOfHistoryEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx RiseOfHistoryEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib = %RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo RiseOfHistoryEngineDynamicGameStaticX64DebugLib = %RiseOfHistoryEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx RiseOfHistoryEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib = %RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx RiseOfHistoryEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo RiseOfHistoryEngineStaticGameDynamicWin32DebugLib = %RiseOfHistoryEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx RiseOfHistoryEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib = %RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx RiseOfHistoryEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo RiseOfHistoryEngineStaticGameDynamicX64DebugLib = %RiseOfHistoryEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx RiseOfHistoryEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib = %RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx RiseOfHistoryEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause