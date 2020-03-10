@echo on

echo EngineInclude = %EngineInclude%
echo %cd%
setx EngineInclude "%cd%\..\Code" 

echo EngineWin32DebugLib = %EngineWin32DebugLib%
echo %cd%
setx EngineWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo EngineWin32ReleaseLib = %EngineWin32ReleaseLib%
echo %cd%
setx EngineWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo EngineX64DebugLib = %EngineX64DebugLib%
echo %cd%
setx EngineX64DebugLib "%cd%\..\x64\DebugWindows" 

echo EngineX64ReleaseLib = %EngineX64ReleaseLib%
echo %cd%
setx EngineX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo EngineStaticWin32DebugLib = %EngineStaticWin32DebugLib%
echo %cd%
setx EngineStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo EngineStaticWin32ReleaseLib = %EngineStaticWin32ReleaseLib%
echo %cd%
setx EngineStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo EngineStaticX64DebugLib = %EngineStaticX64DebugLib%
echo %cd%
setx EngineStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo EngineStaticX64ReleaseLib = %EngineStaticX64ReleaseLib%
echo %cd%
setx EngineStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

pause