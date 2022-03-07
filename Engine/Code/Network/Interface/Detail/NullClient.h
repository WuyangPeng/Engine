///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 14:29)

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
        NullClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD uint64_t Connect() noexcept final;
        void AsyncConnect() noexcept final;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) noexcept final;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) noexcept final;

        void Receive() noexcept final;
        void AsyncReceive() noexcept final;
        void ImmediatelySend(uint64_t socketID) noexcept final;
        void ImmediatelyAsyncSend(uint64_t socketID) noexcept final;

        NODISCARD uint64_t GetSocketID() const noexcept final;

        NODISCARD bool EventFunction(MAYBE_UNUSED const CallbackParameters& callbackParameters) noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_CLIENT_H
