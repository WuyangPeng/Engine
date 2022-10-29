///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 0:58)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "TcpSocketConnect.h"
#include "System/Network/SocketPrototypes.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <exception>
#include <iostream>

SystemToolset::TcpSocketConnect::TcpSocketConnect(WinSocket winSocket)
    : winSocket{ winSocket },
      connectParameter{ "Configuration/EnvironmentVariable.json", "TcpPort" },
      address{ connectParameter.GetWinSockInternetAddress() },
      connectTime{ connectParameter.GetConnectTime() }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::TcpSocketConnect::IsValid() const noexcept
{
    if (System::IsSocketValid(winSocket))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void SystemToolset::TcpSocketConnect::Connect()
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    std::cout << "׼��connect������\n";
    auto connectFailureTime = 0;
    while (!System::Connect(winSocket, &address))
    {
        Connect(connectFailureTime);

        ++connectFailureTime;
    }
}

void SystemToolset::TcpSocketConnect::Connect(int connectFailureTime)
{
    std::cout << "connectʧ�ܣ�����connect������\n";

    if (connectTime <= connectFailureTime)
    {
        throw std::runtime_error("Connect ʧ�ܡ�\n");
    }
}
