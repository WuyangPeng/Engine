///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:39)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H

#include "CoreTools/Threading/Mutex.h"

#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
    class TestMessageEvent : public NetworkMessageEvent
    {
    public:
        using ClassType = TestMessageEvent;
        using ParentType = NetworkMessageEvent;

    public:
        explicit TestMessageEvent(CoreTools::DisableNotThrow disableNotThrow);
        virtual ~TestMessageEvent() noexcept;
        TestMessageEvent(const TestMessageEvent& rhs) = delete;
        TestMessageEvent& operator=(const TestMessageEvent& rhs) = delete;
        TestMessageEvent(TestMessageEvent&& rhs) noexcept = delete;
        TestMessageEvent& operator=(TestMessageEvent&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD uint64_t GetCallBackTime() const noexcept;

        void SetServerWeakPtr(const ServerSharedPtr& ptr) noexcept;

    private:
        uint64_t callBackTime;
        CoreTools::Mutex testMessageEventCriticalSection;
        ServerWeakPtr serverWeakPtr;
    };

    using TestMessageEventSharedPtr = std::shared_ptr<TestMessageEvent>;
    using ConstTestMessageEventSharedPtr = std::shared_ptr<const TestMessageEvent>;
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
