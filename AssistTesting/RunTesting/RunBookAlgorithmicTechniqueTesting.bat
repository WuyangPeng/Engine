@echo on 

start /d %AssistTestingWin32DebugLib% BookAlgorithmicTechniqueTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookAlgorithmicTechniqueTesting.exe
start /d %AssistTestingX64DebugLib% BookAlgorithmicTechniqueTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookAlgorithmicTechniqueTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookAlgorithmicTechniqueTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookAlgorithmicTechniqueTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookAlgorithmicTechniqueTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookAlgorithmicTechniqueTestingStatic.exe

pause