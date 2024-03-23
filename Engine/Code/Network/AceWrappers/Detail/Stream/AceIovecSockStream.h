/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:31)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "AceSockStream.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceIovecSockStream : public AceSockStream
    {
    public:
        using ClassType = AceIovecSockStream;
        using ParentType = AceSockStream;

    public:
        AceIovecSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
