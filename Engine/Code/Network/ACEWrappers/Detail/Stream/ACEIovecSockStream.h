///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:04)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "ACESockStream.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACEIovecSockStream : public ACESockStream
    {
    public:
        using ClassType = ACEIovecSockStream;
        using ParentType = ACESockStream;

    public:
        ACEIovecSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
