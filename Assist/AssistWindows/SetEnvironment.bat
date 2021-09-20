@echo on

echo AssistInclude = %AssistInclude%
echo %cd%
setx AssistInclude "%cd%\..\Code" 

echo AssistEngineering = %AssistEngineering%
echo %cd%
setx AssistEngineering "%cd%\.." 

echo AssistWin32DebugLib = %AssistWin32DebugLib%
echo %cd%
setx AssistWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo AssistWin32ReleaseLib = %AssistWin32ReleaseLib%
echo %cd%
setx AssistWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo AssistX64DebugLib = %AssistX64DebugLib%
echo %cd%
setx AssistX64DebugLib "%cd%\..\x64\DebugWindows" 

echo AssistX64ReleaseLib = %AssistX64ReleaseLib%
echo %cd%
setx AssistX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo AssistStaticWin32DebugLib = %AssistStaticWin32DebugLib%
echo %cd%
setx AssistStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo AssistStaticWin32ReleaseLib = %AssistStaticWin32ReleaseLib%
echo %cd%
setx AssistStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo AssistStaticX64DebugLib = %AssistStaticX64DebugLib%
echo %cd%
setx AssistStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo AssistStaticX64ReleaseLib = %AssistStaticX64ReleaseLib%
echo %cd%
setx AssistStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

pause