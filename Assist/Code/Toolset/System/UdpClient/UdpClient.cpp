///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 17:27)

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
