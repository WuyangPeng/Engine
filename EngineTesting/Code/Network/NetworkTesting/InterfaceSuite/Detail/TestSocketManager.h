// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.4 (2020/03/13 11:31)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H

#include "TestMessageEvent.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <atomic>

namespace Network
{
    class TestSocketManager : public SocketManager
    {
    public:
        using ClassType = TestSocketManager;
        using ParentType = SocketManager;

    public:
        explicit TestSocketManager(uint32_t messageID);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        uint64_t GetCallBackTime() const noexcept;

        bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

        int GetAsyncConnectCount() const noexcept;
        int GetAsyncReceiveCount() const noexcept;
        int GetAsyncAcceptorCount() const noexcept;
        int GetAsyncSendCount() const noexcept;

        void SetServerWeakPtr(const ServerSharedPtr& ptr) noexcept;

    private:
        void InitEvent(uint64_t socketID) override;

    private:
        uint32_t m_MessageID;
        TestMessageEventSharedPtr m_TestMessageEvent;
        // 回调函数只对下列四个原子变量进行操作，所以没有另外加锁。
        std::atomic_int m_AsyncConnectCount;
        std::atomic_int m_AsyncAcceptorCount;
        std::atomic_int m_AsyncReceiveCount;
        std::atomic_int m_AsyncSendCount;
    };

    using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;
    using ConstTestSocketManagerSharedPtr = std::shared_ptr<const TestSocketManager>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
