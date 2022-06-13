///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:33)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H

#include "BoostSockTesting.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

namespace Network
{
    class BoostSockStreamTesting : public BoostSockTesting
    {
    public:
        using ClassType = BoostSockStreamTesting;
        using ParentType = BoostSockTesting;

    public:
        explicit BoostSockStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    protected:
        using TestingType = SockStream;
        using TestingTypeSharedPtr = std::shared_ptr<SockStream>;

    protected:
        void ServerThread();
        void DoServerThread();
        void ServerNoReceiveThread();
        void DoServerNoReceiveThread();
        void ClientThread();
        void DoClientThread();
        void ClientNoSendThread();
        void DoClientNoSendThread();
        void CreateMessage();
        void DestroyMessage();
        NODISCARD MessageBufferSharedPtr CreateMessageBuffer() const;
        void VerificationMessageBuffer(const MessageBufferSharedPtr& messageBuffer);

        NODISCARD uint64_t ClientConnect(const ClientSharedPtr& client);
        void ClientSend(const ClientSharedPtr& client, uint64_t socketID, const TestSocketManagerSharedPtr& testSocketManager);
        void ClientReceive(const ClientSharedPtr& client, const TestSocketManagerSharedPtr& testSocketManager);

        NODISCARD static constexpr int GetAcceptTime() noexcept
        {
            return acceptTime;
        }

        NODISCARD static constexpr int GetAsynchronousAcceptTime() noexcept
        {
            return asynchronousAcceptTime;
        }

        NODISCARD static constexpr int GetSynchronizeAcceptTime() noexcept
        {
            return synchronizeAcceptTime;
        }

        NODISCARD static constexpr int GetConnectTime() noexcept
        {
            return connectTime;
        }

        NODISCARD static constexpr int GetAsynchronousConnectTime() noexcept
        {
            return asynchronousConnectTime;
        }

        NODISCARD static constexpr int GetSynchronizeConnectTime() noexcept
        {
            return synchronizeConnectTime;
        }

        NODISCARD static constexpr int GetSendTime() noexcept
        {
            return sendTime;
        }

        NODISCARD static constexpr int GetSynchronizeSendTime() noexcept
        {
            return synchronizeSendTime;
        }

        NODISCARD static constexpr int GetAsynchronousSendTime() noexcept
        {
            return asynchronousSendTime;
        }

        NODISCARD static constexpr int GetReceiveTime() noexcept
        {
            return receiveTime;
        }

        NODISCARD static constexpr int GetSynchronizeReceiveTime() noexcept
        {
            return synchronizeReceiveTime;
        }

        NODISCARD static constexpr int GetAsynchronousReceiveTime() noexcept
        {
            return asynchronousReceiveTime;
        }

    private:
        // Release版本异步回调的数值要足够大，否则测试时异步回调还未执行。
        static constexpr auto acceptTime = 100000000;
        static constexpr auto synchronizeAcceptTime = 1000;
        static constexpr auto asynchronousAcceptTime = 100000000;
        static constexpr auto connectTime = 100;
        static constexpr auto synchronizeConnectTime = 100;
        static constexpr auto asynchronousConnectTime = 100000000;

        static constexpr auto sendTime = 100000000;
        static constexpr auto synchronizeSendTime = 1000;
        static constexpr auto asynchronousSendTime = 100000000;
        static constexpr auto receiveTime = 100;
        static constexpr auto synchronizeReceiveTime = 1000;
        static constexpr auto asynchronousReceiveTime = 100000000;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H