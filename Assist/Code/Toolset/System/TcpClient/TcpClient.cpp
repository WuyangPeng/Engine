/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 20:43)

#include "TcpClient.h"
#include "Toolset/System/SystemToolset/WinSock/TcpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void SystemToolset::TcpClient()
{
    const auto winSockStart = WinSockStart::Create();

    const auto tcpSocket = TcpSocket::Create();

    tcpSocket.Connect();
    tcpSocket.Send();
}