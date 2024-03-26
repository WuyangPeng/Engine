/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 20:37)

#include "UdpClient.h"
#include "Toolset/System/SystemToolset/WinSock/UdpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void SystemToolset::UdpClient()
{
    const auto winSockStart = WinSockStart::Create();

    const auto udpSocket = UdpSocket::Create();

    udpSocket.Send();
}
