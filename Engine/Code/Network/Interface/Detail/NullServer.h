///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 14:31)

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
        NullServer(const MessageEventManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) noexcept override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) noexcept override;

        NODISCARD bool EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept override;

    private:
        NODISCARD bool WaitForMultipleEvents() noexcept override;
        NODISCARD bool HandleConnections(MessageEventManager& socketManager) noexcept override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& socketManager) noexcept override;
        NODISCARD bool ImmediatelySend() noexcept override;
        NODISCARD bool ImmediatelySend(uint64_t socketID) noexcept override;
        void ImmediatelyAsyncSend(uint64_t socketID) noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SERVER_H
