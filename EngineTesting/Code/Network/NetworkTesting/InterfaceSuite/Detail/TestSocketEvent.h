///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:55)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H

#include "TestMessageEvent.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <atomic>

namespace Network
{
    class TestSocketEvent final : public CoreTools::EventInterface
    {
    public:
        using ClassType = TestSocketEvent;
        using ParentType = EventInterface;

        using TestSocketEventSharedPtr = std::shared_ptr<TestSocketEvent>;

    public:
        NODISCARD static TestSocketEventSharedPtr Create();

        explicit TestSocketEvent() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

        NODISCARD int GetAsyncConnectCount() const noexcept;
        NODISCARD int GetAsyncReceiveCount() const noexcept;
        NODISCARD int GetAsyncAcceptorCount() const noexcept;
        NODISCARD int GetAsyncSendCount() const noexcept;

    private:
        // 回调函数只对下列四个原子变量进行操作，所以没有另外加锁。
        std::atomic_int asyncConnectCount;
        std::atomic_int asyncAcceptorCount;
        std::atomic_int asyncReceiveCount;
        std::atomic_int asyncSendCount;
    };

    using TestSocketEventSharedPtr = std::shared_ptr<TestSocketEvent>;
    using ConstTestSocketEventSharedPtr = std::shared_ptr<const TestSocketEvent>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H
