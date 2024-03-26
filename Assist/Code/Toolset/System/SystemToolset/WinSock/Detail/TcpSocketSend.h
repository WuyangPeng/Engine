/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:23)

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