///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 09:05)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H

#include "TestMessageEvent.h"
#include "Network/Interface/Server.h"
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
        // �ص�����ֻ�������ĸ�ԭ�ӱ������в���������û�����������
        std::atomic_int asyncConnectCount;
        std::atomic_int asyncAcceptorCount;
        std::atomic_int asyncReceiveCount;
        std::atomic_int asyncSendCount;
    };

    using TestSocketEventSharedPtr = std::shared_ptr<TestSocketEvent>;
    using ConstTestSocketEventSharedPtr = std::shared_ptr<const TestSocketEvent>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_EVENT_H
