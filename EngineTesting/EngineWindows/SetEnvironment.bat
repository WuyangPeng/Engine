@echo on

echo EngineTestingInclude = %EngineTestingInclude%
echo %cd%
setx EngineTestingInclude "%cd%\..\Code" 

echo EngineTestingWin32DebugLib = %EngineTestingWin32DebugLib%
echo %cd%
setx EngineTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo EngineTestingWin32ReleaseLib = %EngineTestingWin32ReleaseLib%
echo %cd%
setx EngineTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo EngineTestingX64DebugLib = %EngineTestingX64DebugLib%
echo %cd%
setx EngineTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo EngineTestingX64ReleaseLib = %EngineTestingX64ReleaseLib%
echo %cd%
setx EngineTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo EngineTestingStaticWin32DebugLib = %EngineTestingStaticWin32DebugLib%
echo %cd%
setx EngineTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo EngineTestingStaticWin32ReleaseLib = %EngineTestingStaticWin32ReleaseLib%
echo %cd%
setx EngineTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo EngineTestingStaticX64DebugLib = %EngineTestingStaticX64DebugLib%
echo %cd%
setx EngineTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo EngineTestingStaticX64ReleaseLib = %EngineTestingStaticX64ReleaseLib%
echo %cd%
setx EngineTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

pause