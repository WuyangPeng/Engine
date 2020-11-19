@echo on

echo TheLastOverlordInclude = %TheLastOverlordInclude%
echo %cd%
setx TheLastOverlordInclude "%cd%\..\Code" 

echo TheLastOverlordWin32DebugLib = %TheLastOverlordWin32DebugLib%
echo %cd%
setx TheLastOverlordWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo TheLastOverlordWin32ReleaseLib = %TheLastOverlordWin32ReleaseLib%
echo %cd%
setx TheLastOverlordWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo TheLastOverlordX64DebugLib = %TheLastOverlordX64DebugLib%
echo %cd%
setx TheLastOverlordX64DebugLib "%cd%\..\x64\DebugWindows" 

echo TheLastOverlordX64ReleaseLib = %TheLastOverlordX64ReleaseLib%
echo %cd%
setx TheLastOverlordX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo TheLastOverlordStaticWin32DebugLib = %TheLastOverlordStaticWin32DebugLib%
echo %cd%
setx TheLastOverlordStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo TheLastOverlordStaticWin32ReleaseLib = %TheLastOverlordStaticWin32ReleaseLib%
echo %cd%
setx TheLastOverlordStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo TheLastOverlordStaticX64DebugLib = %TheLastOverlordStaticX64DebugLib%
echo %cd%
setx TheLastOverlordStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo TheLastOverlordStaticX64ReleaseLib = %TheLastOverlordStaticX64ReleaseLib%
echo %cd%
setx TheLastOverlordStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo TheLastOverlordEngineDynamicGameStaticWin32DebugLib = %TheLastOverlordEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx TheLastOverlordEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib = %TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx TheLastOverlordEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo TheLastOverlordEngineDynamicGameStaticX64DebugLib = %TheLastOverlordEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx TheLastOverlordEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo TheLastOverlordEngineDynamicGameStaticX64ReleaseLib = %TheLastOverlordEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx TheLastOverlordEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo TheLastOverlordEngineStaticGameDynamicWin32DebugLib = %TheLastOverlordEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx TheLastOverlordEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib = %TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx TheLastOverlordEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo TheLastOverlordEngineStaticGameDynamicX64DebugLib = %TheLastOverlordEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx TheLastOverlordEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo TheLastOverlordEngineStaticGameDynamicX64ReleaseLib = %TheLastOverlordEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx TheLastOverlordEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause