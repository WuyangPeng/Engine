@echo on 

start /d %AssistTestingWin32DebugLib% BookDirectXTestingD.exe
start /d %AssistTestingWin32ReleaseLib% BookDirectXTesting.exe
start /d %AssistTestingX64DebugLib% BookDirectXTestingD.exe
start /d %AssistTestingX64ReleaseLib% BookDirectXTesting.exe
start /d %AssistTestingStaticWin32DebugLib% BookDirectXTestingStaticD.exe
start /d %AssistTestingStaticWin32ReleaseLib% BookDirectXTestingStatic.exe
start /d %AssistTestingStaticX64DebugLib% BookDirectXTestingStaticD.exe
start /d %AssistTestingStaticX64ReleaseLib% BookDirectXTestingStatic.exe

pause