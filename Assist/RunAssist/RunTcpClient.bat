@echo on 

start /d %AssistWin32DebugLib% TcpClientD.exe
start /d %AssistWin32ReleaseLib% TcpClient.exe
start /d %AssistX64DebugLib% TcpClientD.exe
start /d %AssistX64ReleaseLib% TcpClient.exe
start /d %AssistStaticWin32DebugLib% TcpClientStaticD.exe
start /d %AssistStaticWin32ReleaseLib% TcpClientStatic.exe
start /d %AssistStaticX64DebugLib% TcpClientStaticD.exe
start /d %AssistStaticX64ReleaseLib% TcpClientStatic.exe

pause