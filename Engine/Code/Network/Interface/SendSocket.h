///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:00)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SendSocket
    {
    public:
        using ClassType = SendSocket;
        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;

    public:
        SendSocket() noexcept;
        virtual ~SendSocket() noexcept = default;
        SendSocket(const SendSocket& rhs) = delete;
        SendSocket& operator=(const SendSocket& rhs) = delete;
        SendSocket(SendSocket&& rhs) noexcept = delete;
        SendSocket& operator=(SendSocket&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;
        virtual void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;
    };

    using SendSocketSharedPtr = std::shared_ptr<SendSocket>;
    using ConstSendSocketSharedPtr = std::shared_ptr<const SendSocket>;
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_H
