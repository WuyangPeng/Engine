///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:15)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SERVER_H
#define NETWORK_NETWORK_INTERFACE_NULL_SERVER_H

#include "Network/NetworkDll.h"

#include "ServerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullServer : public ServerImpl
    {
    public:
        using ClassType = NullServer;
        using ParentType = ServerImpl;

    public:
        NullServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) noexcept override;

        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) noexcept override;

    private:
        NODISCARD bool WaitForMultipleEvents() noexcept override;
        NODISCARD bool HandleConnections() noexcept override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& aMessageEventManager) noexcept override;
        NODISCARD bool ImmediatelySend() noexcept override;
        NODISCARD bool ImmediatelySend(int64_t socketId) noexcept override;
        void ImmediatelyAsyncSend(int64_t socketId) noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SERVER_H
