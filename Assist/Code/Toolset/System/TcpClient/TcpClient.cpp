///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 14:59)

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