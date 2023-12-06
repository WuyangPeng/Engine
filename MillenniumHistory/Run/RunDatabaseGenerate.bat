@echo on
 
start /d %MillenniumHistoryWin32DebugLib% DatabaseGenerateD.exe
start /d %MillenniumHistoryWin32ReleaseLib% DatabaseGenerate.exe
start /d %MillenniumHistoryX64DebugLib% DatabaseGenerateD.exe
start /d %MillenniumHistoryX64ReleaseLib% DatabaseGenerate.exe
start /d %MillenniumHistoryStaticWin32DebugLib% DatabaseGenerateStaticD.exe
start /d %MillenniumHistoryStaticWin32ReleaseLib% DatabaseGenerateStatic.exe
start /d %MillenniumHistoryStaticX64DebugLib% DatabaseGenerateStaticD.exe
start /d %MillenniumHistoryStaticX64ReleaseLib% DatabaseGenerateStatic.exe

start /d %MillenniumHistoryEngineStaticGameDynamicWin32DebugLib% DatabaseGenerateStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicWin32ReleaseLib% DatabaseGenerateStatic.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64DebugLib% DatabaseGenerateStaticD.exe
start /d %MillenniumHistoryEngineStaticGameDynamicX64ReleaseLib% DatabaseGenerateStatic.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32DebugLib% DatabaseGenerateD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticWin32ReleaseLib% DatabaseGenerate.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64DebugLib% DatabaseGenerateD.exe
start /d %MillenniumHistoryEngineDynamicGameStaticX64ReleaseLib% DatabaseGenerate.exe

pause