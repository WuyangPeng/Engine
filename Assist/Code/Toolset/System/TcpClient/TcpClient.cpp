///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:16)

#include "TcpClient.h"
#include "Toolset/System/SystemToolset/WinSock/TcpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void SystemToolset::TcpClient()
{
    auto winSockStart = SystemToolset::WinSockStart::Create();

    auto tcpSocket = SystemToolset::TcpSocket::Create();

    tcpSocket.Connect();
    tcpSocket.Send();
}