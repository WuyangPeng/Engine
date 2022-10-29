///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 23:48)

#include "UdpClient.h" 
#include "Toolset/System/SystemToolset/WinSock/UdpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void SystemToolset::UdpClient()
{
    auto winSockStart = SystemToolset::WinSockStart::Create();

    auto udpSocket = SystemToolset::UdpSocket::Create();

    udpSocket.Send();
}
