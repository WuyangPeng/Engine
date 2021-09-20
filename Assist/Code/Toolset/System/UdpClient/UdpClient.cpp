///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 15:00)

#include "UdpClient.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "Toolset/System/SystemToolset/WinSock/UdpSocket.h"
#include "Toolset/System/SystemToolset/WinSock/WinSockStart.h"

void System::UdpClient()
{
    SystemToolset::WinSockStart winSockStart{ CoreTools::DisableNotThrow::Disable };

    SystemToolset::UdpSocket udpSocket{ CoreTools::DisableNotThrow::Disable };

    udpSocket.Send();
}
