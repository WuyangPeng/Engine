///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:35)

#ifndef NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H
#define NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H

#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
    class TestNetworkMessageEvent final : public NetworkMessageEvent
    {
    public:
        using ClassType = TestNetworkMessageEvent;
        using ParentType = NetworkMessageEvent;

    public:
        TestNetworkMessageEvent() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void CallBackEvent(int64_t socketId, const ConstMessageInterfaceSharedPtr& message) override;

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
