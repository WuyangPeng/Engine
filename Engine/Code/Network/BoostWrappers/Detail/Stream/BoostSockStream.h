//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:28)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockStream : public SockStreamImpl
    {
    public:
        using ClassType = BoostSockStream;
        using ParentType = SockStreamImpl;

    public:
        BoostSockStream();
        ~BoostSockStream() noexcept = 0;
        BoostSockStream(const BoostSockStream& rhs) = default;
        BoostSockStream& operator=(const BoostSockStream& rhs) = default;
        BoostSockStream(BoostSockStream&& rhs) noexcept = default;
        BoostSockStream& operator=(BoostSockStream&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] BoostSockStreamType& GetBoostSockStream() noexcept override;

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        [[nodiscard]] bool CloseHandle() override;

        [[nodiscard]] bool EnableNonBlock() override;

        [[nodiscard]] const std::string GetRemoteAddress() const override;
        [[nodiscard]] int GetRemotePort() const override;

    protected:
        [[nodiscard]] int HandleReceive(const MessageBufferSharedPtr& messageBuffer);
        void HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

    private:
        void AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);
        void AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);

        virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) = 0;

    private:
        BoostSockStreamType m_Socket;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
