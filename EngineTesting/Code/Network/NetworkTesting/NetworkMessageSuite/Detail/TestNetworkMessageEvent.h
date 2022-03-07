// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:40)

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

        int GetValue() const noexcept;
        int64_t GetNowTime() const noexcept;

    private:
        int m_Value;
        int64_t m_NowTime;
    };

    using TestNetworkMessageEventSharedPtr = std::shared_ptr<TestNetworkMessageEvent>;
    using ConstTestNetworkMessageEventSharedPtr = std::shared_ptr<const TestNetworkMessageEvent>;
}

#endif  // NETWORK_NETWORK_MESSAGE_TEST_NETWORK_MESSAGE_EVENT_H
