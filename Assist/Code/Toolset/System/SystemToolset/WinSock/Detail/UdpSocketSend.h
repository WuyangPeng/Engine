///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 0:57)

#ifndef SYSTEM_TOOLSET_UDP_SOCKET_SEND_H
#define SYSTEM_TOOLSET_UDP_SOCKET_SEND_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "ConnectParameter.h"
#include "SocketSend.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_HIDDEN_DECLARE UdpSocketSend final : public SocketSend
    {
    public:
        using ClassType = UdpSocketSend;
        using ParentType = SocketSend;

    public:
        explicit UdpSocketSend(WinSocket winSocket);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send() override;

    private:
        ConnectParameter connectParameter;
    };
}

#endif  // SYSTEM_TOOLSET_UDP_SOCKET_SEND_H