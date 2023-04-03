@echo on

echo MillenniumHistoryInclude = %MillenniumHistoryInclude%
echo %cd%
setx MillenniumHistoryInclude "%cd%\..\Code" 

echo MillenniumHistoryEngineering = %MillenniumHistoryEngineering%
echo %cd%
setx MillenniumHistoryEngineering "%cd%\.." 

echo MillenniumHistoryWin32DebugLib = %MillenniumHistoryWin32DebugLib%
echo %cd%
setx MillenniumHistoryWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo MillenniumHistoryWin32ReleaseLib = %MillenniumHistoryWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo MillenniumHistoryX64DebugLib = %MillenniumHistoryX64DebugLib%
echo %cd%
setx MillenniumHistoryX64DebugLib "%cd%\..\x64\DebugWindows" 

echo MillenniumHistoryX64ReleaseLib = %MillenniumHistoryX64ReleaseLib%
echo %cd%
setx MillenniumHistoryX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo MillenniumHistoryStaticWin32DebugLib = %MillenniumHistoryStaticWin32DebugLib%
echo %cd%
setx MillenniumHistoryStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo MillenniumHistoryStaticWin32ReleaseLib = %MillenniumHistoryStaticWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo MillenniumHistoryStaticX64DebugLib = %MillenniumHistoryStaticX64DebugLib%
echo %cd%
setx MillenniumHistoryStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo MillenniumHistoryStaticX64ReleaseLib = %MillenniumHistoryStaticX64ReleaseLib%
echo %cd%
setx MillenniumHistoryStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo MillenniumHistoryEngineDynamicGameStaticWin32DebugLib = %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx MillenniumHistoryEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib = %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo MillenniumHistoryEngineDynamicGameStaticX64DebugLib = %MillenniumHistoryEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx MillenniumHistoryEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib = %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo MillenniumHistoryEngineStaticGameDynamicWin32DebugLib = %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx MillenniumHistoryEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib = %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo MillenniumHistoryEngineStaticGameDynamicX64DebugLib = %MillenniumHistoryEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx MillenniumHistoryEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib = %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause