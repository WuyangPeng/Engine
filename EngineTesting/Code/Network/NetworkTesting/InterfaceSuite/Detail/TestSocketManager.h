// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/13 11:31)

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
        // �ص�����ֻ�������ĸ�ԭ�ӱ������в���������û�����������
        std::atomic_int m_AsyncConnectCount;
        std::atomic_int m_AsyncAcceptorCount;
        std::atomic_int m_AsyncReceiveCount;
        std::atomic_int m_AsyncSendCount;
    };

    using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;
    using ConstTestSocketManagerSharedPtr = std::shared_ptr<const TestSocketManager>;

}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_SOCKET_MANAGER_H
