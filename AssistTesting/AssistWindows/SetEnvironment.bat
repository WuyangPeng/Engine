@echo on

echo AssistTestingInclude = %AssistTestingInclude%
echo %cd%
setx AssistTestingInclude "%cd%\..\Code" 

echo AssistTestingEngineering = %AssistTestingEngineering%
echo %cd%
setx AssistTestingEngineering "%cd%\.." 

echo AssistTestingWin32DebugLib = %AssistTestingWin32DebugLib%
echo %cd%
setx AssistTestingWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo AssistTestingWin32ReleaseLib = %AssistTestingWin32ReleaseLib%
echo %cd%
setx AssistTestingWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo AssistTestingX64DebugLib = %AssistTestingX64DebugLib%
echo %cd%
setx AssistTestingX64DebugLib "%cd%\..\x64\DebugWindows" 

echo AssistTestingX64ReleaseLib = %AssistTestingX64ReleaseLib%
echo %cd%
setx AssistTestingX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo AssistTestingStaticWin32DebugLib = %AssistTestingStaticWin32DebugLib%
echo %cd%
setx AssistTestingStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo AssistTestingStaticWin32ReleaseLib = %AssistTestingStaticWin32ReleaseLib%
echo %cd%
setx AssistTestingStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo AssistTestingStaticX64DebugLib = %AssistTestingStaticX64DebugLib%
echo %cd%
setx AssistTestingStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo AssistTestingStaticX64ReleaseLib = %AssistTestingStaticX64ReleaseLib%
echo %cd%
setx AssistTestingStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

pause