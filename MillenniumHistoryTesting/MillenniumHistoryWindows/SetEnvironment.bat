@echo on

echo MillenniumHistoryTestingInclude = %MillenniumHistoryTestingInclude%
echo %cd%
setx MillenniumHistoryTestingInclude "%cd%\..\Code" 

echo MillenniumHistoryTestingEngineering = %MillenniumHistoryTestingEngineering%
echo %cd%
setx MillenniumHistoryTestingEngineering "%cd%\.." 

echo MillenniumHistoryTestingWin32DebugLib = %MillenniumHistoryTestingWin32DebugLib%
echo %cd%
setx MillenniumHistoryTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo MillenniumHistoryTestingWin32ReleaseLib = %MillenniumHistoryTestingWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo MillenniumHistoryTestingX64DebugLib = %MillenniumHistoryTestingX64DebugLib%
echo %cd%
setx MillenniumHistoryTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo MillenniumHistoryTestingX64ReleaseLib = %MillenniumHistoryTestingX64ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo MillenniumHistoryTestingStaticWin32DebugLib = %MillenniumHistoryTestingStaticWin32DebugLib%
echo %cd%
setx MillenniumHistoryTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo MillenniumHistoryTestingStaticWin32ReleaseLib = %MillenniumHistoryTestingStaticWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo MillenniumHistoryTestingStaticX64DebugLib = %MillenniumHistoryTestingStaticX64DebugLib%
echo %cd%
setx MillenniumHistoryTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo MillenniumHistoryTestingStaticX64ReleaseLib = %MillenniumHistoryTestingStaticX64ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib = %MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx MillenniumHistoryTestingEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib = %MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib = %MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx MillenniumHistoryTestingEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib = %MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib = %MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx MillenniumHistoryTestingEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib = %MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib = %MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx MillenniumHistoryTestingEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib = %MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx MillenniumHistoryTestingEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause