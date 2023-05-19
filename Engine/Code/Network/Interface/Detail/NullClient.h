///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:13)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_NULL_CLIENT_H

#include "Network/NetworkDll.h"

#include "ClientImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullClient final : public ClientImpl
    {
    public:
        using ClassType = NullClient;
        using ParentType = ClientImpl;

    public:
        NullClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int64_t Connect() noexcept override;
        void AsyncConnect() noexcept override;

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept override;

        void Receive() noexcept override;
        void AsyncReceive() noexcept override;
        void ImmediatelySend(int64_t socketId) noexcept override;
        void ImmediatelyAsyncSend(int64_t socketId) noexcept override;

        NODISCARD int64_t GetSocketId() const noexcept override;

        NODISCARD bool EventFunction(const CallbackParameters& callbackParameters) noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_CLIENT_H
