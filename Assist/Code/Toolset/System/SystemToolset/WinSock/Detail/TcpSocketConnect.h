///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/27 0:57)

#ifndef SYSTEM_TOOLSET_TCP_SOCKET_CONNECT_H
#define SYSTEM_TOOLSET_TCP_SOCKET_CONNECT_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "ConnectParameter.h"

#include <string>

namespace SystemToolset
{
    class SYSTEM_TOOLSET_HIDDEN_DECLARE TcpSocketConnect final
    {
    public:
        using ClassType = TcpSocketConnect;

        using WinSocket = System::WinSocket;
        using WinSockInternetAddress = System::WinSockInternetAddress;

    public:
        explicit TcpSocketConnect(WinSocket winSocket);

        CLASS_INVARIANT_DECLARE;

        void Connect();

    private:
        void Connect(int connectFailureTime);

    private:
        WinSocket winSocket;
        ConnectParameter connectParameter;
        WinSockInternetAddress address;
        int connectTime;
    };
}

#endif  // SYSTEM_TOOLSET_TCP_SOCKET_CONNECT_H