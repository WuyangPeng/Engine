///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/27 23:46)

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