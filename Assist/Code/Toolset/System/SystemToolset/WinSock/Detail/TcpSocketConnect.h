///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:21)

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