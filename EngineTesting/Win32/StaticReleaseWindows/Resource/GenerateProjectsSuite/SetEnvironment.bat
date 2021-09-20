@echo on

echo GameTemplateInclude = %GameTemplateInclude%
echo %cd%
setx GameTemplateInclude "%cd%\..\Export\Code" 

echo GameTemplateWin32DebugLib = %GameTemplateWin32DebugLib%
echo %cd%
setx GameTemplateWin32DebugLib "%cd%\..\Export\Win32\DebugWindows" 

echo GameTemplateWin32ReleaseLib = %GameTemplateWin32ReleaseLib%
echo %cd%
setx GameTemplateWin32ReleaseLib "%cd%\..\Export\Win32\ReleaseWindows" 

echo GameTemplateX64DebugLib = %GameTemplateX64DebugLib%
echo %cd%
setx GameTemplateX64DebugLib "%cd%\..\Export\x64\DebugWindows" 

echo GameTemplateX64ReleaseLib = %GameTemplateX64ReleaseLib%
echo %cd%
setx GameTemplateX64ReleaseLib "%cd%\..\Export\x64\ReleaseWindows" 

echo GameTemplateStaticWin32DebugLib = %GameTemplateStaticWin32DebugLib%
echo %cd%
setx GameTemplateStaticWin32DebugLib "%cd%\..\Export\Win32\StaticDebugWindows" 

echo GameTemplateStaticWin32ReleaseLib = %GameTemplateStaticWin32ReleaseLib%
echo %cd%
setx GameTemplateStaticWin32ReleaseLib "%cd%\..\Export\Win32\StaticReleaseWindows" 

echo GameTemplateStaticX64DebugLib = %GameTemplateStaticX64DebugLib%
echo %cd%
setx GameTemplateStaticX64DebugLib "%cd%\..\Export\x64\StaticDebugWindows" 

echo GameTemplateStaticX64ReleaseLib = %GameTemplateStaticX64ReleaseLib%
echo %cd%
setx GameTemplateStaticX64ReleaseLib "%cd%\..\Export\x64\StaticReleaseWindows" 

echo GameTemplateTestingInclude = %GameTemplateTestingInclude%
echo %cd%
setx GameTemplateTestingInclude "%cd%\..\ExportTesting\Code" 

pause