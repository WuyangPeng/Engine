///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:38)

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
