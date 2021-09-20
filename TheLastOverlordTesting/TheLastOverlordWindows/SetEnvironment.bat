@echo on

echo TheLastOverlordTestingInclude = %TheLastOverlordTestingInclude%
echo %cd%
setx TheLastOverlordTestingInclude "%cd%\..\Code"

echo TheLastOverlordTestingEngineering = %TheLastOverlordTestingEngineering%
echo %cd%
setx TheLastOverlordTestingEngineering "%cd%\.." 

echo TheLastOverlordTestingWin32DebugLib = %TheLastOverlordTestingWin32DebugLib%
echo %cd%
setx TheLastOverlordTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo TheLastOverlordTestingWin32ReleaseLib = %TheLastOverlordTestingWin32ReleaseLib%
echo %cd%
setx TheLastOverlordTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo TheLastOverlordTestingX64DebugLib = %TheLastOverlordTestingX64DebugLib%
echo %cd%
setx TheLastOverlordTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo TheLastOverlordTestingX64ReleaseLib = %TheLastOverlordTestingX64ReleaseLib%
echo %cd%
setx TheLastOverlordTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo TheLastOverlordTestingStaticWin32DebugLib = %TheLastOverlordTestingStaticWin32DebugLib%
echo %cd%
setx TheLastOverlordTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo TheLastOverlordTestingStaticWin32ReleaseLib = %TheLastOverlordTestingStaticWin32ReleaseLib%
echo %cd%
setx TheLastOverlordTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo TheLastOverlordTestingStaticX64DebugLib = %TheLastOverlordTestingStaticX64DebugLib%
echo %cd%
setx TheLastOverlordTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo TheLastOverlordTestingStaticX64ReleaseLib = %TheLastOverlordTestingStaticX64ReleaseLib%
echo %cd%
setx TheLastOverlordTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib = %TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx TheLastOverlordTestingEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib = %TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx TheLastOverlordTestingEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib = %TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx TheLastOverlordTestingEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib = %TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx TheLastOverlordTestingEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib = %TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx TheLastOverlordTestingEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib = %TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx TheLastOverlordTestingEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib = %TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx TheLastOverlordTestingEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib = %TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx TheLastOverlordTestingEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 


pause