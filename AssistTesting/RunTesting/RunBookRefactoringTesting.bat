@echo on 

start /d %AssistTestingWin32DebugLib% BookRefactoringTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookRefactoringTesting.exe
start /d %AssistTestingX64DebugLib% BookRefactoringTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookRefactoringTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookRefactoringTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookRefactoringTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookRefactoringTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookRefactoringTestingStatic.exe

pause