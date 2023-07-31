///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:16)

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