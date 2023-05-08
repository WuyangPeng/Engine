///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 13:42)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H

#include "TestMessageEvent.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <atomic>

namespace Network
{
    class TestSocketManager : public CoreTools::EventInterface
    {
    public:
        using ClassType = TestSocketManager;
        using ParentType = EventInterface;

        using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;

    public:
        NODISCARD static TestSocketManagerSharedPtr Create(uint32_t messageID);

        explicit TestSocketManager(uint32_t messageID);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD uint64_t GetCallBackTime() const noexcept;

        bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

        NODISCARD int GetAsyncConnectCount() const noexcept;
        NODISCARD int GetAsyncReceiveCount() const noexcept;
        NODISCARD int GetAsyncAcceptorCount() const noexcept;
        NODISCARD int GetAsyncSendCount() const noexcept;

        void SetServerWeakPtr(const ServerSharedPtr& ptr) noexcept;

    private:
        void InitEvent(uint64_t socketID) noexcept;

    private:
        uint32_t messageID;
        TestMessageEventSharedPtr testMessageEvent;
        // �ص�����ֻ�������ĸ�ԭ�ӱ������в���������û�����������
        std::atomic_int asyncConnectCount;
        std::atomic_int asyncAcceptorCount;
        std::atomic_int asyncReceiveCount;
        std::atomic_int asyncSendCount;
    };

    using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;
    using ConstTestSocketManagerSharedPtr = std::shared_ptr<const TestSocketManager>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
