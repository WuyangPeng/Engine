///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 17:27)

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
