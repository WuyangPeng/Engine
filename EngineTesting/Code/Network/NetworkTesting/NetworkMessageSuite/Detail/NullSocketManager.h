///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:14)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H

#include "TestNetworkMessageEvent.h"
#include "Network/NetworkMessage/SocketManager.h"

namespace Network
{
    class NullSocketManager : public SocketManager
    {
    public:
        using ClassType = NullSocketManager;
        using ParentType = SocketManager;
        using CallbackParameters = CoreTools::CallbackParameters;

    public:
        explicit NullSocketManager(int64_t messageID);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool EventFunction(const CallbackParameters& callbackParameters) noexcept override;

        NODISCARD int GetValue() const noexcept;

    private:
        void InitEvent(uint64_t socketID) override;

    private:
        TestNetworkMessageEventSharedPtr event;
        int64_t messageID;
    };

    using NullSocketManagerSharedPtr = std::shared_ptr<NullSocketManager>;
    using ConstNullSocketManagerSharedPtr = std::shared_ptr<const NullSocketManager>;
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NULL_SOCKET_MANAGER_H
