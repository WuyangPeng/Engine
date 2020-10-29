//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 14:33)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "ACESockStream.h"

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

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_IOVEC_SOCK_CONNECTOR_H
