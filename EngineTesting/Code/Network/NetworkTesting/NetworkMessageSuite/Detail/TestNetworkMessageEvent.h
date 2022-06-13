///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:18)

#ifndef NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H
#define NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H

#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
    class TestNetworkMessageEvent : public NetworkMessageEvent
    {
    public:
        using ClassType = TestNetworkMessageEvent;
        using ParentType = NetworkMessageEvent;

    public:
        TestNetworkMessageEvent() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD int GetValue() const noexcept;
        NODISCARD int64_t GetNowTime() const noexcept;

    private:
        int value;
        int64_t nowTime;
    };

    using TestNetworkMessageEventSharedPtr = std::shared_ptr<TestNetworkMessageEvent>;
    using ConstTestNetworkMessageEventSharedPtr = std::shared_ptr<const TestNetworkMessageEvent>;
}

#endif  // NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H
