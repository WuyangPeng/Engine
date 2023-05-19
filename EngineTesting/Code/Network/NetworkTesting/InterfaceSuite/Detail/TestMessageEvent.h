///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 17:08)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H

#include "CoreTools/Threading/Mutex.h"

#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
    class TestMessageEvent final : public NetworkMessageEvent
    {
    public:
        using ClassType = TestMessageEvent;
        using ParentType = NetworkMessageEvent;

    public:
        explicit TestMessageEvent(CoreTools::DisableNotThrow disableNotThrow);
        ~TestMessageEvent() noexcept;
        TestMessageEvent(const TestMessageEvent& rhs) = delete;
        TestMessageEvent& operator=(const TestMessageEvent& rhs) = delete;
        TestMessageEvent(TestMessageEvent&& rhs) noexcept = delete;
        TestMessageEvent& operator=(TestMessageEvent&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void CallBackEvent(int64_t socketId, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD int64_t GetCallBackTime() const noexcept;

        void SetServerWeakPtr(const ServerSharedPtr& aServer) noexcept;

    private:
        int64_t callBackTime;
        CoreTools::Mutex testMessageEventCriticalSection;
        ServerWeakPtr server;
    };

    using TestMessageEventSharedPtr = std::shared_ptr<TestMessageEvent>;
    using ConstTestMessageEventSharedPtr = std::shared_ptr<const TestMessageEvent>;
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
