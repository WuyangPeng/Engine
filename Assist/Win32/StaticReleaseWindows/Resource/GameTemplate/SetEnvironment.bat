@echo on

echo ToolsetGameTemplateInclude = %ToolsetGameTemplateInclude%
echo %cd%
setx ToolsetGameTemplateInclude "%cd%\..\Export\Code" 

echo ToolsetGameTemplateWin32DebugLib = %ToolsetGameTemplateWin32DebugLib%
echo %cd%
setx ToolsetGameTemplateWin32DebugLib "%cd%\..\Export\Win32\DebugWindows" 

echo ToolsetGameTemplateWin32ReleaseLib = %ToolsetGameTemplateWin32ReleaseLib%
echo %cd%
setx ToolsetGameTemplateWin32ReleaseLib "%cd%\..\Export\Win32\ReleaseWindows" 

echo ToolsetGameTemplateX64DebugLib = %ToolsetGameTemplateX64DebugLib%
echo %cd%
setx ToolsetGameTemplateX64DebugLib "%cd%\..\Export\x64\DebugWindows" 

echo ToolsetGameTemplateX64ReleaseLib = %ToolsetGameTemplateX64ReleaseLib%
echo %cd%
setx ToolsetGameTemplateX64ReleaseLib "%cd%\..\Export\x64\ReleaseWindows" 

echo ToolsetGameTemplateStaticWin32DebugLib = %ToolsetGameTemplateStaticWin32DebugLib%
echo %cd%
setx ToolsetGameTemplateStaticWin32DebugLib "%cd%\..\Export\Win32\StaticDebugWindows" 

echo ToolsetGameTemplateStaticWin32ReleaseLib = %ToolsetGameTemplateStaticWin32ReleaseLib%
echo %cd%
setx ToolsetGameTemplateStaticWin32ReleaseLib "%cd%\..\Export\Win32\StaticReleaseWindows" 

echo ToolsetGameTemplateStaticX64DebugLib = %ToolsetGameTemplateStaticX64DebugLib%
echo %cd%
setx ToolsetGameTemplateStaticX64DebugLib "%cd%\..\Export\x64\StaticDebugWindows" 

echo ToolsetGameTemplateStaticX64ReleaseLib = %ToolsetGameTemplateStaticX64ReleaseLib%
echo %cd%
setx ToolsetGameTemplateStaticX64ReleaseLib "%cd%\..\Export\x64\StaticReleaseWindows" 

echo ToolsetGameTemplateEngineDynamicGameStaticWin32DebugLib = %ToolsetGameTemplateEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx ToolsetGameTemplateEngineDynamicGameStaticWin32DebugLib "%cd%\..\Export\Win32\GameStaticDebugWindows" 

echo ToolsetGameTemplateEngineDynamicGameStaticWin32ReleaseLib = %ToolsetGameTemplateEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx ToolsetGameTemplateEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Export\Win32\GameStaticReleaseWindows" 

echo ToolsetGameTemplateEngineDynamicGameStaticX64DebugLib = %ToolsetGameTemplateEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx ToolsetGameTemplateEngineDynamicGameStaticX64DebugLib "%cd%\..\Export\x64\GameStaticDebugWindows" 

echo ToolsetGameTemplateEngineDynamicGameStaticX64ReleaseLib = %ToolsetGameTemplateEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx ToolsetGameTemplateEngineDynamicGameStaticX64ReleaseLib "%cd%\..\Export\x64\GameStaticReleaseWindows" 

echo ToolsetGameTemplateEngineStaticGameDynamicWin32DebugLib = %ToolsetGameTemplateEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx ToolsetGameTemplateEngineStaticGameDynamicWin32DebugLib "%cd%\..\Export\Win32\EngineStaticDebugWindows" 

echo ToolsetGameTemplateEngineStaticGameDynamicWin32ReleaseLib = %ToolsetGameTemplateEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx ToolsetGameTemplateEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Export\Win32\EngineStaticReleaseWindows" 

echo ToolsetGameTemplateEngineStaticGameDynamicX64DebugLib = %ToolsetGameTemplateEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx ToolsetGameTemplateEngineStaticGameDynamicX64DebugLib "%cd%\..\Export\x64\EngineStaticDebugWindows" 

echo ToolsetGameTemplateEngineStaticGameDynamicX64ReleaseLib = %ToolsetGameTemplateEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx ToolsetGameTemplateEngineStaticGameDynamicX64ReleaseLib "%cd%\..\Export\x64\EngineStaticReleaseWindows" 

pause