/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:23)

#ifndef SYSTEM_TOOLSET_TCP_SOCKET_SEND_H
#define SYSTEM_TOOLSET_TCP_SOCKET_SEND_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "SocketSend.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_HIDDEN_DECLARE TcpSocketSend final : public SocketSend
    {
    public:
        using ClassType = TcpSocketSend;
        using ParentType = SocketSend;

    public:
        explicit TcpSocketSend(WinSocket winSocket) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send() noexcept override;
    };
}

#endif  // SYSTEM_TOOLSET_TCP_SOCKET_SEND_H