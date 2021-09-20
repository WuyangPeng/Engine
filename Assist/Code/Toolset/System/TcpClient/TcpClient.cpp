///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/05 14:59)

#include "TcpClient.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "Toolset/System/SystemToolset/WinSock/TcpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void System::TcpClient()
{
    SystemToolset::WinSockStart winSockStart{ CoreTools::DisableNotThrow::Disable };

    SystemToolset::TcpSocket tcpSocket{ CoreTools::DisableNotThrow::Disable };
    tcpSocket.Connect();
    tcpSocket.Send();
}