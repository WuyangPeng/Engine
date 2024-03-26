/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:26)

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
    return System::IsSocketValid(winSocket);
}

#endif  // OPEN_CLASS_INVARIANT

void SystemToolset::TcpSocketConnect::Connect() const
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    std::cout << "准备connect服务器\n";
    auto connectFailureTime = 0;
    while (!System::Connect(winSocket, &address))
    {
        Connect(connectFailureTime);

        ++connectFailureTime;
    }
}

void SystemToolset::TcpSocketConnect::Connect(int connectFailureTime) const
{
    std::cout << "connect失败，重新connect服务器\n";

    if (connectTime <= connectFailureTime)
    {
        throw std::runtime_error("Connect 失败。\n");
    }
}
