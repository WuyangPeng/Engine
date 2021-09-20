@echo on

echo GameInclude = %GameInclude%
echo %cd%
setx GameInclude "%cd%\..\Code" 

echo GameEngineering = %GameEngineering%
echo %cd%
setx GameEngineering "%cd%\.." 

echo GameWin32DebugLib = %GameWin32DebugLib%
echo %cd%
setx GameWin32DebugLib "%cd%\..\Win32\DebugWindows" 

echo GameWin32ReleaseLib = %GameWin32ReleaseLib%
echo %cd%
setx GameWin32ReleaseLib "%cd%\..\Win32\ReleaseWindows" 

echo GameX64DebugLib = %GameX64DebugLib%
echo %cd%
setx GameX64DebugLib "%cd%\..\x64\DebugWindows" 

echo GameX64ReleaseLib = %GameX64ReleaseLib%
echo %cd%
setx GameX64ReleaseLib "%cd%\..\x64\ReleaseWindows" 

echo GameStaticWin32DebugLib = %GameStaticWin32DebugLib%
echo %cd%
setx GameStaticWin32DebugLib "%cd%\..\Win32\StaticDebugWindows" 

echo GameStaticWin32ReleaseLib = %GameStaticWin32ReleaseLib%
echo %cd%
setx GameStaticWin32ReleaseLib "%cd%\..\Win32\StaticReleaseWindows" 

echo GameStaticX64DebugLib = %GameStaticX64DebugLib%
echo %cd%
setx GameStaticX64DebugLib "%cd%\..\x64\StaticDebugWindows" 

echo GameStaticX64ReleaseLib = %GameStaticX64ReleaseLib%
echo %cd%
setx GameStaticX64ReleaseLib "%cd%\..\x64\StaticReleaseWindows" 

echo GameEngineDynamicGameStaticWin32DebugLib = %GameEngineDynamicGameStaticWin32DebugLib%
echo %cd%
setx GameEngineDynamicGameStaticWin32DebugLib "%cd%\..\Win32\GameStaticDebugWindows" 

echo GameEngineDynamicGameStaticWin32ReleaseLib = %GameEngineDynamicGameStaticWin32ReleaseLib%
echo %cd%
setx GameEngineDynamicGameStaticWin32ReleaseLib "%cd%\..\Win32\GameStaticReleaseWindows" 

echo GameEngineDynamicGameStaticX64DebugLib = %GameEngineDynamicGameStaticX64DebugLib%
echo %cd%
setx GameEngineDynamicGameStaticX64DebugLib "%cd%\..\x64\GameStaticDebugWindows" 

echo GameEngineDynamicGameStaticX64ReleaseLib = %GameEngineDynamicGameStaticX64ReleaseLib%
echo %cd%
setx GameEngineDynamicGameStaticX64ReleaseLib "%cd%\..\x64\GameStaticReleaseWindows" 

echo GameEngineStaticGameDynamicWin32DebugLib = %GameEngineStaticGameDynamicWin32DebugLib%
echo %cd%
setx GameEngineStaticGameDynamicWin32DebugLib "%cd%\..\Win32\EngineStaticDebugWindows" 

echo GameEngineStaticGameDynamicWin32ReleaseLib = %GameEngineStaticGameDynamicWin32ReleaseLib%
echo %cd%
setx GameEngineStaticGameDynamicWin32ReleaseLib "%cd%\..\Win32\EngineStaticReleaseWindows" 

echo GameEngineStaticGameDynamicX64DebugLib = %GameEngineStaticGameDynamicX64DebugLib%
echo %cd%
setx GameEngineStaticGameDynamicX64DebugLib "%cd%\..\x64\EngineStaticDebugWindows" 

echo GameEngineStaticGameDynamicX64ReleaseLib = %GameEngineStaticGameDynamicX64ReleaseLib%
echo %cd%
setx GameEngineStaticGameDynamicX64ReleaseLib "%cd%\..\x64\EngineStaticReleaseWindows" 

pause