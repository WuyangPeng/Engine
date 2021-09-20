@echo on 

start /d %AssistTestingWin32DebugLib% BookOtherLanguagesTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookOtherLanguagesTesting.exe
start /d %AssistTestingX64DebugLib% BookOtherLanguagesTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookOtherLanguagesTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookOtherLanguagesTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookOtherLanguagesTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookOtherLanguagesTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookOtherLanguagesTestingStatic.exe

pause