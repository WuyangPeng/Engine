///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:42)

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
        // 回调函数只对下列四个原子变量进行操作，所以没有另外加锁。
        std::atomic_int asyncConnectCount;
        std::atomic_int asyncAcceptorCount;
        std::atomic_int asyncReceiveCount;
        std::atomic_int asyncSendCount;
    };

    using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;
    using ConstTestSocketManagerSharedPtr = std::shared_ptr<const TestSocketManager>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
