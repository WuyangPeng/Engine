@echo on 

start /d %AssistWin32DebugLib% UdpClientD.exe
start /d %AssistWin32ReleaseLib% UdpClient.exe
start /d %AssistX64DebugLib% UdpClientD.exe
start /d %AssistX64ReleaseLib% UdpClient.exe
start /d %AssistStaticWin32DebugLib% UdpClientStaticD.exe
start /d %AssistStaticWin32ReleaseLib% UdpClientStatic.exe
start /d %AssistStaticX64DebugLib% UdpClientStaticD.exe
start /d %AssistStaticX64ReleaseLib% UdpClientStatic.exe

pause